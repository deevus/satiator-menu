#include <stdlib.h>
#include "entity.h"
#include "menu.h"
#include "gamebrowser.h"
#include "savemanager.h"
#include "jo/jo.h"

void LoadBackground() {
    jo_img bg;

    jo_bin_loader(&bg, "IMAGES", "MENUBG.BIN", JO_COLOR_Transparent);
    jo_set_background_sprite(&bg, 0, 0);
    jo_free_img(&bg);
}

EMenu *entity_menu_create() {
    EMenu *menu = malloc(sizeof(EMenu));
    EHeader *header = (EHeader*)menu;

    header->id = &header;
    header->name = "Menu";
    header->type = ET_MENU;
    header->next = (EGameBrowser*)entity_game_browser_create();
    header->prev = NULL;

    LoadBackground();

    return menu;
}

void entity_menu_draw(EMenu *menu) {
    EHeader *header = (EHeader *)menu;

    entity_draw(header->next);

    jo_printf(10, 9, "%s", header->name);
}

void entity_menu_free(EMenu *menu) {
    entity_free(((EHeader*)menu)->next);

    free(menu);
}
