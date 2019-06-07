#include "c_background.h"
#include <stdlib.h>
#include <stdbool.h>
#include <jo/jo.h>

Background *component_background_create(const char *directory, const char *filename, jo_color transparent_color) {
    Background *background = (Background *)malloc(sizeof(Background));

    ComponentHeader header        = {CT_BACKGROUND, false};
    background->header            = header;
    background->directory         = directory;
    background->filename          = filename;
    background->transparent_color = transparent_color;
    background->image_id          = 0;

    return background;
}
