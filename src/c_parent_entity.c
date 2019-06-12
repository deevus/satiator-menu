#include "c_parent_entity.h"

#include <stdlib.h>

ParentEntityComponent *component_parent_entity_create(Entity *parent) {
    ParentEntityComponent *component = (ParentEntityComponent *)malloc(sizeof(ParentEntityComponent));
    ComponentHeader header = {CT_PARENT_ENTITY, false};

    component->header = header;
    component->parent = parent;

    return component;
}
