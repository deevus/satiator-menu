#ifndef GAMEBROWSER_H
#define GAMEBROWSER_H

#include "entity.h"

typedef struct {
    EHeader header;
} EGameBrowser;

void entity_game_browser_draw(EGameBrowser *game_browser);

EGameBrowser *entity_game_browser_create();

#endif
