#ifndef MENU_H
#define MENU_H

#include "entity.h"
#include "jo/jo.h"

typedef struct {
    EHeader header;
    EType current;
} EMenu;

EMenu *entity_menu_create();

void entity_menu_draw(EMenu *menu);

void entity_menu_free(EMenu *menu);

#endif
