#include "s_assets.h"
#include "entity.h"
#include <stdlib.h>
#include "component.h"
#include "c_background.h"
#include <jo/jo.h>
#include <string.h>

void system_assets_process(EntityArray *entities) {
    // backgrounds
    for (size_t i = 0; i < entities->size; i++) {
        ComponentArray *components = entities->data[i].components;

        if (components->types & (CT_BACKGROUND | CT_TRANSFORM)) {
            Background *background = (Background *)component_find(components, CT_BACKGROUND);

            if (strstr(background->filename, "BIN")) {
                background->image_id = jo_sprite_add_bin(background->directory, background->filename, background->transparent_color);
            } else {
                background->image_id = jo_sprite_add_tga(background->directory, background->filename, background->transparent_color);
            }
        }
    }
}
