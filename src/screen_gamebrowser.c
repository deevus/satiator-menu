#include "screen_gamebrowser.h"

static void screen_gamebrowser_update(EScreen *screen) {
    jo_printf(10, 10, "MIC DROP");
}

static void screen_gamebrowser_startup(EScreen *screen) {
}

const EScreen *screen_gamebrowser_create() {
    EHeader *header = entity_create(ET_SCREEN);

    // callbacks
    header->startup = &screen_gamebrowser_startup;
    header->update  = &screen_gamebrowser_update;

    EScreen *screen = (EScreen*)header;
    linkedlist_init(&screen->children);

    return screen;
}
