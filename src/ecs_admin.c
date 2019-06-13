#include "ecs_admin.h"

#include <stdlib.h>
#include <jo/jo.h>
#include <stdint.h>

#include "entity.h"
#include "linkedlist.h"
#include "font.h"

#include "s_font.h"
#include "s_assets.h"
#include "s_input.h"
#include "s_draw.h"

static uint16_t last_ticks = 0;

extern linkedlist_t g_entities;

ECSAdmin *ecs_admin_create() {
    linkedlist_init(&g_entities);

    ECSAdmin *admin = (ECSAdmin *)malloc(sizeof(ECSAdmin));

    admin->fonts = system_font_init();

    return admin;
}

void ecs_admin_update(ECSAdmin *admin) {
    // first run - load assets
    if (last_ticks == 0) {
        system_assets_process(&g_entities);
    }

    uint16_t ticks       = jo_get_ticks();
    uint16_t delta_ticks = ticks - last_ticks;
    last_ticks           = ticks;

    /*system_input_process(entities, delta_ticks);*/
    system_draw_process(&g_entities, admin->fonts, delta_ticks);
}

void ecs_admin_free(ECSAdmin *admin) {
}
