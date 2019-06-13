#ifndef _E_ENTITY_H
#define _E_ENTITY_H

#include <stdint.h>
#include "component.h"
#include "linkedlist.h"

typedef struct {
    uint16_t id;
    ComponentArray *components;
} Entity;

typedef struct {
    size_t size;
    Entity *data[];
} EntityArray;

linkedlist_t g_entities;

Entity *entity_create(ComponentArray *components);

#endif
