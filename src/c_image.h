#ifndef _C_IMAGE_H
#define _C_IMAGE_H

#include <jo/jo.h>
#include "component.h"
#include <stdint.h>

typedef struct {
    ComponentHeader header;
    uint16_t image_id;
    jo_color transparent_color;
} ImageComponent;

ImageComponent *component_image_create(jo_color transparent_color);

#endif
