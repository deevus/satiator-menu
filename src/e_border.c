#include "e_border.h"

#include <stdlib.h>
#include <jo/jo.h>

#include "component.h"
#include "c_file.h"
#include "c_image.h"
#include "c_transform.h"

Entity *entity_border_create() {
    size_t num_components = 3;
    ComponentArray *components = (ComponentArray *)malloc(sizeof(ComponentArray) + sizeof(ComponentHeader *) * num_components);

    components->size  = num_components;
    components->types = CT_FILE | CT_IMAGE | CT_TRANSFORM;

    Position position = {0, 0, 100};
    components->data[0] = (ComponentHeader *)component_file_create("IMAGES", "BORDER.TGA");
    components->data[1] = (ComponentHeader *)component_image_create(JO_COLOR_Green);
    components->data[2] = (ComponentHeader *)component_transform_create(position);

    return entity_create(components);
}

