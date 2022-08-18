#pragma once
#include "../includes/stivale2.h"

typedef struct  {
    unsigned char r,g,b;

}RGB;


void InitGraphics(struct stivale2_struct_tag_framebuffer *buffer);

void FillScreen(RGB color);