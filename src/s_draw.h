#ifndef _S_DRAW_H
#define _S_DRAW_H

#include "entity.h"
#include <stdint.h>

void system_draw_process(EntityArray *entities, const uint16_t delta_time);

#endif
