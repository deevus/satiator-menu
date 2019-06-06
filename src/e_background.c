#include "e_background.h"
#include "c_background.h"
#include "component.h"
#include <stdlib.h>

const Entity *entity_background_create() {
    ComponentArray *components = (ComponentArray *)malloc(sizeof(ComponentArray) + sizeof(ComponentHeader));

    components->size  = 1;
    components->types = CT_BACKGROUND;

    components->data[0] = *(ComponentHeader *)component_background_create("IMAGES", "MENUBG.BIN");

    return entity_create(components);
}
