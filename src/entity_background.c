#include "entity_background.h"
#include "jo/jo.h"
#include <string.h>

static void entity_background_update(EBackground *background) {
    EHeader *header = (EHeader*)background;

    jo_set_background_sprite(&background->img, header->position[0], header->position[1]);
}

static void entity_background_startup(EBackground *background) {
    if (strstr(background->name, "BIN")) {
        jo_bin_loader(&background->img, background->directory, background->name, background->transparent_color);
    } else {
        jo_tga_loader(&background->img, background->directory, background->name, background->transparent_color);
    }
}

static void entity_background_destroy(EBackground *background) {
    jo_free_img(&background->img);
}

EBackground *entity_background_create(char *directory, char *name, jo_color transparent_color) {
    EHeader *header = entity_create(ET_BACKGROUND);
    header->position[0] = 0;
    header->position[1] = 0;

    header->startup = &entity_background_startup;
    header->update  = &entity_background_update;
    header->destroy = &entity_background_destroy;

    EBackground *background = (EBackground*)header;
    background->directory = directory;
    background->name = name;
    background->transparent_color = transparent_color;

    return background;
}
