#ifndef _C_TEXT_H
#define _C_TEXT_H

#include <stdbool.h>
#include <jo/jo.h>
#include <stdint.h>

#include "font.h"
#include "component.h"
#include "c_transform.h"

typedef struct {
    ComponentHeader header;
    FontType font_type;
    bool centered;
    float scale;
    char *value;
} TextComponent;

#define FONT_DIR "FONTS"

TextComponent *component_text_create(char *value, FontType font_type, bool centered, float scale);

#endif
