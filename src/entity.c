#include <stdlib.h>
#include "menu.h"
#include "entity.h"
#include "savemanager.h"
#include "gamebrowser.h"

void entity_draw(EHeader *header) {
    switch (header->type) {
        case ET_MENU:
            entity_menu_draw((EMenu*)header);
            break;
        case ET_GAME_BROWSER:
            entity_game_browser_draw((EGameBrowser*)header);
            break;
        case ET_SAVE_MANAGER:
            entity_save_manager_draw((ESaveManager*)header);
            break;
        default:
            break;
    }
}

void entity_free(EHeader *header) {
    switch (header->type) {
        case ET_MENU:
            entity_menu_free((EMenu*)header);
            break;
        case ET_GAME_BROWSER:
            entity_game_browser_free((EGameBrowser*)header);
            break;
        case ET_SAVE_MANAGER:
            entity_save_manager_free((ESaveManager*)header);
            break;
        default:
            break;
    }
}

EHeader *entity_create(EType type) {
    switch (type) {
        case ET_MENU:
            return entity_menu_create();
        case ET_GAME_BROWSER:
            return entity_game_browser_create();
        case ET_SAVE_MANAGER:
            return entity_save_manager_create();
        default:
            return NULL;
    }
}
