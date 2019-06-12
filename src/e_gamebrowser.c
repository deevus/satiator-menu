#include "e_gamebrowser.h"

#include <stdlib.h>

#include "component.h"
#include "c_transform.h"
#include "c_text.h"
#include "c_parent_entity.h"
#include "font.h"

Entity *entity_gamebrowser_create(Entity *parent) {
    ComponentArray *components = (ComponentArray *)malloc(sizeof(ComponentArray) + sizeof(ComponentHeader *) * GBC_COUNT);

    components->size  = GBC_COUNT;
    components->types = CT_TEXT | CT_TRANSFORM;

    Position position = {0, 0, 0};
    components->data[GBC_TRANSFORM] = (ComponentHeader *)component_transform_create(position);
    components->data[GBC_HELLO] = (ComponentHeader *)component_text_create("Game Browser", FT_MOSWHT, true, 1.0f);
    components->data[GBC_PARENT] = (ComponentHeader *)component_parent_entity_create(parent);

    return entity_create(components);
}
