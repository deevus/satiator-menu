#include <stdlib.h>
#include "entity.h"

EHeader *entity_create(EType type) {
    EHeader *entity;

    switch (type) {
        case ET_SCREEN:
            entity = (EHeader*)malloc(sizeof(EScreen));
            break;
        case ET_TEXT:
            entity = (EHeader*)malloc(sizeof(EText));
            break;
        default:
            jo_core_error("Invalid entity type: %d", type);
            return NULL;
    }

    return entity;
}

void entity_startup(EHeader *entity) {
    void (*startup)(EHeader) = entity->startup;

    if (startup) {
        (*startup)(*entity);
    }
}

void entity_update(EHeader *entity) {
    void (*update)(EHeader) = entity->update;

    if (update) {
        (*update)(*entity);
    }
}
