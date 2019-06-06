#ifndef _E_ENTITY_H
#define _E_ENTITY_H

#include <stdint.h>
#include "component.h"

typedef struct {
    uint16_t id;
    ComponentArray *components;
} Entity;

typedef struct {
    uint16_t size;
    Entity data[];
} EntityArray;

Entity *entity_create(ComponentArray *components);

#endif
