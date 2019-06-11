#ifndef __FONT_H
#define __FONT_H

#include <jo/jo.h>
#include <stdlib.h>

typedef enum {
    FT_MOSWHT,
    FT_COUNT,
} FontType;

typedef struct {
    size_t size;
    jo_font *data[];
} FontArray;

jo_font *font_get(FontArray *fonts, FontType font_type);

#endif
