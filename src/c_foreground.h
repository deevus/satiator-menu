#ifndef _C_FOREGROUND_H
#define _C_FOREGROUND_H

#include <jo/jo.h>
#include "component.h"
#include <stdint.h>

typedef struct {
    ComponentHeader header;
    const char *directory;
    const char *filename;
    uint16_t image_id;
    jo_color transparent_color;
} ForegroundComponent;

ForegroundComponent *component_foreground_create(const char *directory, const char *filename, jo_color transparent_color);

#endif

