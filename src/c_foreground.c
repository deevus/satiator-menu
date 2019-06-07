#include "c_foreground.h"
#include <stdlib.h>
#include <stdbool.h>
#include <jo/jo.h>

ForegroundComponent *component_foreground_create(const char *directory, const char *filename, jo_color transparent_color) {
    ForegroundComponent *foreground = (ForegroundComponent *)malloc(sizeof(ForegroundComponent));

    ComponentHeader header        = {CT_BACKGROUND, false};
    foreground->header            = header;
    foreground->directory         = directory;
    foreground->filename          = filename;
    foreground->transparent_color = transparent_color;
    foreground->image_id          = 0;

    return foreground;
}

