#ifndef SAVEMANAGER_H
#define SAVEMANAGER_H

#include "entity.h"

typedef struct {
    EHeader header;
} ESaveManager;

ESaveManager *entity_save_manager_create();

void entity_save_manager_draw(ESaveManager *save_manager);

#endif
