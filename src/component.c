#include "component.h"
#include <stdlib.h>

const ComponentHeader *component_create(const ComponentType type) {
    ComponentHeader *header = (ComponentHeader *)malloc(sizeof(ComponentHeader));

    header->type = type;

    return header;
}

const ComponentHeader *component_get_singleton(const ComponentType type);
