#ifndef _E_TRANSFORM_H
#define _E_TRANSFORM_H

#include <stdint.h>

#include "component.h"
#include <jo/jo.h>

typedef struct {
    uint16_t x;
    uint16_t y;
    uint16_t z;
} Position;

typedef struct {
    ComponentHeader header;
    Position position;
} TransformComponent;

TransformComponent *component_transform_create(const Position position);

#endif
