#ifndef _E_TEXT_H
#define _E_TEXT_H

#include <jo/jo.h>
#include <stdint.h>

#include "entity.h"
#include "c_text.h"
#include "font.h"

Entity *entity_text_create(char *value, FontType font_type, bool centered, float scale, uint16_t x, uint16_t y);

#endif
