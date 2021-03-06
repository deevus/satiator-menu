#include <stdlib.h>
#include <jo/jo.h>
#include <string.h>

#include "s_assets.h"

#include "entity.h"
#include "component.h"
#include "c_image.h"
#include "c_file.h"

void system_assets_process(EntityArray *entities) {
    // backgrounds
    for (size_t i = 0; i < entities->size; i++) {
        ComponentArray *components = entities->data[i]->components;

        if (components->types & (CT_FILE | CT_IMAGE)) {
            FileComponent *file   = (FileComponent *)component_find(components, CT_FILE);
            ImageComponent *image = (ImageComponent *)component_find(components, CT_IMAGE);

            if (strstr(file->filename, "BIN")) {
                image->image_id = jo_sprite_add_bin(file->directory, file->filename, image->transparent_color);
            } else {
                image->image_id = jo_sprite_add_tga(file->directory, file->filename, image->transparent_color);
            }
        }
    }
}
