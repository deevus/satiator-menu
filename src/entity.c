#include "entity.h"

#include <stdlib.h>
#include <string.h>
#include <jo/jo.h>

uint16_t next_entity_id = 0;

static void entity_init(Entity *entity, ComponentArray *components) {
    entity->id = next_entity_id++;

    entity->components = components;
}

Entity *entity_create(ComponentArray *components) {
    Entity *entity = (Entity *)malloc(sizeof(Entity));

    entity_init(entity, components);

    linkedlist_insert(&g_entities, entity);

    return entity;
}
