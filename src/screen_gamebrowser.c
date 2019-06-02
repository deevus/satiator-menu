#include "screen_gamebrowser.h"
#include "entity_background.h"
#include "jo/jo.h"
#include <stdlib.h>

static void screen_gamebrowser_update(EScreen *screen) {
    entity_screen_update_children(screen);
}

static void screen_gamebrowser_startup(EScreen *screen) {
    // background
    EBackground *background = entity_background_create("IMAGES", "CHECK.TGA", JO_COLOR_Green);
    linkedlist_insert(screen->children, background);

    // border
    EBackground *border = entity_background_create("IMAGES", "BORDER.TGA", JO_COLOR_Green);
    linkedlist_insert(screen->children, border);

    entity_screen_startup_children(screen);
}

const EScreen *screen_gamebrowser_create() {
    EHeader *header = entity_create(ET_SCREEN);

    // callbacks
    header->startup = &screen_gamebrowser_startup;
    header->update  = &screen_gamebrowser_update;

    EScreen *screen = (EScreen*)header;

    linkedlist_t *children = malloc(sizeof(linkedlist_t));
    linkedlist_init(children);

    screen->children = children;

    return screen;
}