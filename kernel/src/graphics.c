#include "../includes/stivale2.h"
#include "../includes/graphics.h"

struct stivale2_struct_tag_framebuffer *framebuffer;

void InitGraphics(struct stivale2_struct_tag_framebuffer *buffer)
{
    framebuffer = buffer;
}


void FillScreen(RGB color)
{
    for(unsigned int y = 0;y < framebuffer->framebuffer_height;y++)
    {
        for(unsigned int x = 0;x < framebuffer->framebuffer_width;x++)
        {
             *(unsigned int *)(x*4 + (y * framebuffer->framebuffer_pitch) + framebuffer->framebuffer_addr) = color.b | color.g << 8 | color.r << 16;

        }
    }

}