#include "e_checkerboard.h"
#include "c_file.h"
#include "c_image.h"
#include "c_transform.h"
#include "component.h"
#include <stdlib.h>
#include <jo/jo.h>

Entity *entity_checkerboard_create() {
    size_t num_components = 3;
    ComponentArray *components = (ComponentArray *)malloc(sizeof(ComponentArray) + sizeof(ComponentHeader *) * num_components);

    components->size  = num_components;
    components->types = CT_FILE | CT_IMAGE | CT_TRANSFORM;

    Position position = {0, 0, 500};
    components->data[0] = (ComponentHeader *)component_file_create("IMAGES", "CHECK.TGA");
    components->data[1] = (ComponentHeader *)component_image_create(JO_COLOR_Green);
    components->data[2] = (ComponentHeader *)component_transform_create(position);

    return entity_create(components);
}
