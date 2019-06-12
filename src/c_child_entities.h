#ifndef __C_CHILD_ENTITIES_H
#define __C_CHILD_ENTITIES_H

#include "component.h"
#include "entity.h"

typedef struct {
    ComponentHeader header;
    EntityArray *children;
} ChildEntitiesComponent;

ChildEntitiesComponent *component_child_entities_create(EntityArray *children);

#endif

