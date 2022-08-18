#include "includes/stivale2.h"
#include "includes/memory.h"
#include "includes/graphics.h"
#include <stdint.h>
#include <stddef.h>

static uint8_t stack[80048];

static struct stivale2_header_tag_terminal terminal_hdr_tag = {
   .tag = {
   .identifier = STIVALE2_HEADER_TAG_TERMINAL_ID,
   .next = 0
   },
   .flags = 0
};

static struct stivale2_header_tag_framebuffer framebuffer_hdr_tag = {
   .tag = {
   .identifier = STIVALE2_HEADER_TAG_FRAMEBUFFER_ID,
   .next = (uint64_t)&terminal_hdr_tag
   },
   .framebuffer_width  = 0,
   .framebuffer_height = 0,
   .framebuffer_bpp    = 0
};


__attribute__((section(".stivale2hdr"), used))
static struct stivale2_header stivale_hdr = {
   .entry_point = 0,
   .stack = (uintptr_t)stack + sizeof(stack),
   .flags = (1 << 1) | (1 << 2) | (1 << 3) | (1 << 4),
   .tags = (uintptr_t)&framebuffer_hdr_tag
};

void *find_tag(struct stivale2_struct *stivale2_struct,uint64_t tagid)
{
   struct stivale2_tag *current_tag = (void *)stivale2_struct->tags;
   while(current_tag != NULL)
   {
      if(current_tag->identifier == tagid)
      {
         return current_tag;
      }
       current_tag = (void *)current_tag->next;
   }
   return NULL;
}

size_t strlen(const char* str)
{
   size_t len = 0;
   while(str[len] != '\0')
   {
   len++;
   }
   return len;
}

size_t num2string(char* num_buff,uint64_t num)
{
   size_t len = 0;
   uint64_t n = num;
   while(n % 10 != 0)
   {
      num_buff[19 - len] = 48 + (n % 10);
      n /= 10;
      len++;
   }
   return len;
}


void _start(struct stivale2_struct *stivale2_struct) {
   
   struct stivale2_struct_tag_memmap* mmap;
   mmap = find_tag(stivale2_struct, STIVALE2_STRUCT_TAG_MEMMAP_ID);
   InitializeMemory(mmap);
   struct stivale2_struct_tag_framebuffer *screen;
   screen = find_tag(stivale2_struct, STIVALE2_STRUCT_TAG_FRAMEBUFFER_ID);
   InitGraphics(screen);
   RGB color;
   color.r = 47;
   color.g = 110;
   color.b = 96;
   FillScreen(color);

   for (;;) {
      asm ("hlt");
   }  

}
