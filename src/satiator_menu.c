#include "satiator_menu.h"

#include <stdlib.h>
#include <jo/jo.h>

#include "entity.h"
#include "font.h"
#include "e_checkerboard.h"
#include "e_border.h"
#include "e_menu.h"

const EntityArray *satiator_menu_create() {
    size_t num_entities = SMC_COUNT;

    EntityArray *entities = (EntityArray *)malloc(sizeof(EntityArray) + num_entities * sizeof(Entity));
    entities->size = num_entities;

    entities->data[SMC_BACKGROUND] = entity_checkerboard_create();
    entities->data[SMC_BORDER] = entity_border_create();
    entities->data[SMC_MENU] = entity_menu_create();

    return entities;
}
