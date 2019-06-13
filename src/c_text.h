#ifndef _C_TEXT_H
#define _C_TEXT_H

#include <stdbool.h>
#include <jo/jo.h>
#include <stdint.h>

#include "font.h"
#include "component.h"
#include "c_transform.h"

typedef enum {
    TCF_CENTERED = 1 << 0,
} TextComponentFlags;

typedef struct {
    ComponentHeader header;
    FontType font_type;
    float scale;
    char *value;
    TextComponentFlags flags;
} TextComponent;

#define FONT_DIR "FONTS"

TextComponent *component_text_create(char *value, FontType font_type, float scale, TextComponentFlags flags);

#endif
