#ifndef ENTITY_BACKGROUND_H
#define ENTITY_BACKGROUND_H

#include "entity.h"
#include "jo/jo.h"

EBackground *entity_background_create(char *directory, char *name, jo_color transparent_color);

#endif
