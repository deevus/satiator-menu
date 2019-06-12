#ifndef __C_PARENT_ENTITY_H
#define __C_PARENT_ENTITY_H

#include "component.h"
#include "entity.h"

typedef struct {
    ComponentHeader header;
    Entity *parent;
} ParentEntityComponent;

ParentEntityComponent *component_parent_entity_create(Entity *parent);

#endif
