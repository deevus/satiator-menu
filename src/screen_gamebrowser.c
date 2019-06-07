#include <stdlib.h>
#include "entity.h"
#include "screen_gamebrowser.h"
#include "e_background.h"
#include <jo/jo.h>

const EntityArray *screen_gamebrowser_create() {
    size_t num_entities = 1;

    EntityArray *entities = (EntityArray *)malloc(sizeof(EntityArray) + num_entities * sizeof(Entity));
    entities->size = num_entities;
    entities->data[0] = *entity_background_create();

    return entities;
}
