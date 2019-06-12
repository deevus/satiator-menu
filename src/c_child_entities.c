#include "c_child_entities.h"
#include <stdlib.h>

ChildEntitiesComponent *component_child_entities_create(EntityArray *children) {
    ChildEntitiesComponent *component = (ChildEntitiesComponent *)malloc(sizeof(ChildEntitiesComponent));
    ComponentHeader header = {CT_CHILD_ENTITIES, false};

    component->header   = header;
    component->children = children;

    return component;
}
