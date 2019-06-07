#ifndef _E_TRANSFORM_H
#define _E_TRANSFORM_H

#include "component.h"
#include <jo/jo.h>

typedef struct {
    ComponentHeader header;
    jo_pos2D position;
} TransformComponent;

TransformComponent *component_transform_create(jo_pos2D initial_position);

#endif
