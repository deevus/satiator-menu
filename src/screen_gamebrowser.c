#include "screen_gamebrowser.h"

#include <stdlib.h>
#include <jo/jo.h>

#include "entity.h"
#include "font.h"
#include "e_checkerboard.h"
#include "e_text.h"
#include "e_border.h"

const EntityArray *screen_gamebrowser_create() {
    size_t num_entities = 3;

    EntityArray *entities = (EntityArray *)malloc(sizeof(EntityArray) + num_entities * sizeof(Entity));
    entities->size = num_entities;

    entities->data[0] = entity_checkerboard_create();
    entities->data[1] = entity_border_create();
    entities->data[2] = entity_text_create("Hello, world!", FT_MOSWHT, true, 1, 0, 0);

    return entities;
}
