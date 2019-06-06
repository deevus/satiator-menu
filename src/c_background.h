#ifndef _C_BACKGROUND_H
#define _C_BACKGROUND_H

#include <jo/jo.h>
#include "component.h"
#include <stdint.h>

typedef struct {
    ComponentHeader header;
    char *directory;
    char *filename;
    uint16_t image_id;
    jo_img data;
} Background;

const Background *component_background_create(char *directory, char *filename);

#endif
