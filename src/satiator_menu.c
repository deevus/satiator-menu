#include "satiator_menu.h"

#include <stdlib.h>
#include <jo/jo.h>

#include "entity.h"
#include "font.h"
#include "e_checkerboard.h"
#include "e_border.h"

const EntityArray *satiator_menu_create() {
    size_t num_entities = 2;

    EntityArray *entities = (EntityArray *)malloc(sizeof(EntityArray) + num_entities * sizeof(Entity));
    entities->size = num_entities;

    entities->data[0] = entity_checkerboard_create();
    entities->data[1] = entity_border_create();

    return entities;
}
