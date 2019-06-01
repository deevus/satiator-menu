#include <stdlib.h>
#include <stdint.h>
#include "gamebrowser.h"
#include "jo/jo.h"

EGameBrowser *entity_game_browser_create() {
    // create stuff
    EGameBrowser *game_browser = malloc(sizeof(EGameBrowser));
    EHeader *header = (EHeader *)game_browser;

    header->id = &header;
    header->name = "Game Browser";
    header->type = ET_GAME_BROWSER;
    header->next = NULL;
    header->prev = NULL;

    return game_browser;
}

void entity_game_browser_draw(EGameBrowser *game_browser) {
    EHeader *header = (EHeader*)game_browser;

    jo_printf(0, 0, header->name);
}
