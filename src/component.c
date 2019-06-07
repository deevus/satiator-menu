#include "component.h"
#include <stdlib.h>

const ComponentHeader *component_create(const ComponentType type, const bool singleton) {
    ComponentHeader *header = (ComponentHeader *)malloc(sizeof(ComponentHeader));

    header->type      = type;
    header->singleton = singleton;

    return header;
}

const ComponentHeader *component_find(const ComponentArray *components, ComponentType type) {
    for (size_t i = 0; i < components->size; i++) {
        ComponentHeader *component = components->data[i];

        if (component->type == type) {
            return component;
        }
    }

    return NULL;
}
