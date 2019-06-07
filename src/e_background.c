#include "e_background.h"
#include "c_background.h"
#include "c_transform.h"
#include "component.h"
#include <stdlib.h>
#include <jo/jo.h>

const Entity *entity_background_create() {
    size_t num_components = 2;
    ComponentArray *components = (ComponentArray *)malloc(sizeof(ComponentArray) + sizeof(ComponentHeader) * num_components);

    components->size  = num_components;
    components->types = CT_BACKGROUND | CT_TRANSFORM;

    components->data[0] = (ComponentHeader *)component_background_create("IMAGES", "MENUBG.BIN", JO_COLOR_Green);

    jo_pos2D initial_position = {0, 0};
    components->data[1] = (ComponentHeader *)component_transform_create(initial_position);

    return entity_create(components);
}
