#include <stdlib.h>
#include "savemanager.h"

ESaveManager *entity_save_manager_create() {
    ESaveManager *save_manager = malloc(sizeof(ESaveManager));

    return save_manager;
}

void entity_save_manager_draw(ESaveManager *save_manager) {
    // do stuff
}
