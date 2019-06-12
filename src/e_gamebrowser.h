#ifndef __E_GAMEBROWSER_H
#define __E_GAMEBROWSER_H

#include "entity.h"

typedef enum {
    GBC_PARENT,
    GBC_HELLO,
    GBC_TRANSFORM,
    GBC_COUNT,
} GameBrowserComponents;

Entity *entity_gamebrowser_create();

#endif
