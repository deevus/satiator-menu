#include "entity.h"
#include "gamebrowser.h"

void entity_draw(EHeader *header) {
    switch (header->type) {
        case ET_GAME_BROWSER:
            entity_game_browser_draw((EGameBrowser*)header);
            break;
        default:
            break;
    }
}

void entity_free(EHeader *header) {
    switch (header->type) {
        case ET_GAME_BROWSER:
            entity_game_browser_free((EGameBrowser*)header);
            break;
        default:
            break;
    }
}
