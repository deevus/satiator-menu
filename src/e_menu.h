#ifndef __E_MENU_H
#define __E_MENU_H

#include "entity.h"

typedef enum {
    MENU_CHILDREN,
    MENU_TRANSFORM,
    MENU_COUNT,
} MenuComponents;

Entity *entity_menu_create();

#endif
