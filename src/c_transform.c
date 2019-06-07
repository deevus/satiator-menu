#include <stdlib.h>
#include "c_transform.h"
#include <stdbool.h>

TransformComponent *component_transform_create(const jo_pos2D initial_position) {
    TransformComponent *transform = (TransformComponent *)malloc(sizeof(TransformComponent));

    ComponentHeader header = {CT_TRANSFORM, false};
    transform->header      = header;
    transform->position    = initial_position;

    return transform;
}
