#include "c_image.h"
#include <stdlib.h>
#include <stdbool.h>
#include <jo/jo.h>

ImageComponent *component_image_create(jo_color transparent_color) {
    ImageComponent *image = (ImageComponent *)malloc(sizeof(ImageComponent));

    ComponentHeader header   = {CT_IMAGE, false};
    image->header            = header;
    image->transparent_color = transparent_color;
    image->image_id          = 0;

    return image;
}
