#ifndef _S_DRAW_H
#define _S_DRAW_H

#include <stdint.h>

#include "entity.h"
#include "font.h"

void system_draw_process(EntityArray *entities, FontArray *fonts, const uint16_t delta_time);

#endif
