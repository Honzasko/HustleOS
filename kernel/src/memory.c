#include <stdint.h>
#include "../includes/stivale2.h"
#include "../includes/memory.h"

extern uint64_t GetCR3();
extern void SetCR3(uint64_t ptr);

struct stivale2_struct_tag_memmap *memory_map;

void InitializeMemory(struct stivale2_struct_tag_memmap *memmap)
{
    memory_map = memmap;
}