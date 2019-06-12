#ifndef _COMPONENT_H
#define _COMPONENT_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>

typedef enum {
    CT_INPUT          = 1 << 0,
    CT_TRANSFORM      = 1 << 1,
    CT_SPRITE         = 1 << 2,
    CT_DRAW           = 1 << 3,
    CT_FOCUS          = 1 << 4,
    CT_IMAGE          = 1 << 5,
    CT_TEXT           = 1 << 6,
    CT_FILE           = 1 << 8,
    CT_STREAM         = 1 << 9,
    CT_PARENT_ENTITY  = 1 << 10,
    CT_CHILD_ENTITIES = 1 << 11,
} ComponentType;

typedef struct {
    ComponentType type;
    bool singleton;
} ComponentHeader;

typedef struct {
    size_t size;
    ComponentType types;
    ComponentHeader *data[];
} ComponentArray;

const ComponentHeader *component_create(const ComponentType type, const bool singleton);

const ComponentHeader *component_find(const ComponentArray *components, ComponentType type);

#endif
