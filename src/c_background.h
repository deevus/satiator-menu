#ifndef _C_BACKGROUND_H
#define _C_BACKGROUND_H

#include <jo/jo.h>
#include "component.h"
#include <stdint.h>

typedef struct {
    ComponentHeader header;
    const char *directory;
    const char *filename;
    uint16_t image_id;
    jo_color transparent_color;
} Background;

Background *component_background_create(const char *directory, const char *filename, jo_color transparent_color);

#endif
