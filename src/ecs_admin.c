#include "ecs_admin.h"

#include <stdlib.h>
#include <jo/jo.h>
#include <stdint.h>

#include "linkedlist.h"
#include "font.h"

#include "s_font.h"
#include "s_assets.h"
#include "s_input.h"
#include "s_draw.h"

static uint16_t last_ticks = 0;

ECSAdmin *ecs_admin_create(EntityArray *entities) {
    ECSAdmin *admin = (ECSAdmin *)malloc(sizeof(ECSAdmin));

    admin->entities = entities;

    ComponentType types = 0;
    linkedlist_t components_list;
    linkedlist_init(&components_list);

    for (size_t i = 0; i < entities->size; i++) {
        Entity *entity = entities->data[i];
        ComponentArray *components = entity->components;

        for (size_t j = 0; j < components->size; j++) {
            ComponentHeader *component = components->data[j];

            if (component->singleton) {
                if ((types & component->type) == 0) {
                    linkedlist_insert(&components_list, component);
                }
            } else {
                linkedlist_insert(&components_list, component);
            }

            types |= component->type;
        }
    }

    ComponentArray *components = (ComponentArray *)malloc(sizeof(ComponentArray) + components_list.size * sizeof(ComponentHeader *));
    components->size  = components_list.size;
    components->types = types;

    int i = 0;
    const node_t *current = linkedlist_gethead(&components_list);

    while (current) {
        components->data[i] = (ComponentHeader *)current->data;

        current = linkedlist_next(&components_list, current);
        i++;
    }

    admin->components = components;

    admin->fonts = system_font_init();

    return admin;
}

void ecs_admin_update(ECSAdmin *admin) {
    // first run - load assets
    if (last_ticks == 0) {
        system_assets_process(admin->entities);
    }

    uint16_t ticks       = jo_get_ticks();
    uint16_t delta_ticks = ticks - last_ticks;
    last_ticks           = ticks;

    EntityArray *entities = admin->entities;

    system_input_process(entities, delta_ticks);
    system_draw_process(entities, admin->fonts, delta_ticks);
}

void ecs_admin_free(ECSAdmin *admin) {
}
