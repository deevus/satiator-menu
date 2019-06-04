#include "entity_background.h"
#include "jo/jo.h"
#include <string.h>

static void entity_background_update(EBackground *background) {
    EHeader *header = (EHeader*)background;

    // TODO - work out how to draw these using layers rather than sprites
    jo_sprite_draw3D2(background->sprite_id, header->position.x, header->position.y, header->position.z);
}

static void entity_background_startup(EBackground *background) {
    if (strstr(background->name, "BIN")) {
        background->sprite_id = jo_sprite_add_bin(background->directory, background->name, background->transparent_color);
    } else {
        background->sprite_id = jo_sprite_add_tga(background->directory, background->name, background->transparent_color);
    }
}

static void entity_background_destroy(EBackground *background) {
    jo_sprite_free_from(background->sprite_id);
}

EBackground *entity_background_create(char *directory, char *name, jo_color transparent_color, int z_index) {
    printf(z_index);
    EHeader *header = entity_create(ET_BACKGROUND);
    jo_pos3D position = {0, 0, z_index};
    header->position = position;

    header->startup = &entity_background_startup;
    header->update  = &entity_background_update;
    header->destroy = &entity_background_destroy;

    EBackground *background = (EBackground*)header;
    background->directory = directory;
    background->name = name;
    background->transparent_color = transparent_color;

    return background;
}
