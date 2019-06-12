#include "e_menu.h"

#include <stdlib.h>

#include "component.h"
#include "c_transform.h"
#include "c_child_entities.h"

#include "e_gamebrowser.h"

Entity *entity_menu_create() {
    Entity* menu = entity_create(NULL);

    menu->components = (ComponentArray *)malloc(sizeof(ComponentArray) + sizeof(ComponentHeader *) * MENU_COUNT);

    menu->components->size  = MENU_COUNT;
    menu->components->types = CT_CHILD_ENTITIES | CT_TRANSFORM;

    Position position = {0, 0, 0};
    menu->components->data[MENU_TRANSFORM] = (ComponentHeader *)component_transform_create(position);

    EntityArray *children = (EntityArray *)malloc(sizeof(EntityArray) + sizeof(Entity *));

    children->size = 1;
    children->data[0] = entity_gamebrowser_create(menu);

    menu->components->data[MENU_CHILDREN] = (ComponentHeader *)component_child_entities_create(children);

    return menu;
}
