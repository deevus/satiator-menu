#ifndef _S_DRAW_H
#define _S_DRAW_H

#include <stdint.h>

#include "entity.h"
#include "font.h"
#include "linkedlist.h"

void system_draw_process(linkedlist_t *entities, FontArray *fonts, const uint16_t delta_time);

#endif
