#include "e_text.h"

#include <stdlib.h>

#include "component.h"
#include "c_text.h"
#include "c_transform.h"

Entity *entity_text_create(char *value, FontType font_type, bool centered, float scale, uint16_t x, uint16_t y) {
    const size_t num_components = 2;
    ComponentArray *components = (ComponentArray *)malloc(sizeof(ComponentArray) + sizeof(ComponentHeader *) * num_components);

    components->size  = num_components;
    components->types = CT_TEXT | CT_TRANSFORM;

    Position position = {x, y, 0};
    components->data[0] = (ComponentHeader *)component_text_create(value, font_type, centered, scale);
    components->data[1] = (ComponentHeader *)component_transform_create(position);

    return entity_create(components);
}
