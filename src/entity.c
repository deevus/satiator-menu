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
        case ET_BACKGROUND:
            entity = (EHeader*)malloc(sizeof(EBackground));
            break;
        default:
            jo_core_error("Invalid entity type: %d", type);
            return NULL;
    }

    return entity;
}

void entity_startup(EHeader *entity) {
    void (*startup)(EHeader*) = entity->startup;

    if (startup) {
        (*startup)(entity);
    }
}

void entity_update(EHeader *entity) {
    void (*update)(EHeader*) = entity->update;

    if (update) {
        (*update)(entity);
    }
}

void entity_destroy(EHeader *entity) {
    void (*destroy)(EHeader*) = entity->destroy;

    if (destroy) {
        (*destroy)(entity);
    }
}

void entity_screen_update_children(EScreen *entity) {
    const node_t *current = linkedlist_gethead(entity->children);

    while (current) {
        entity_update((EHeader*)current->data);

        current = current->nextptr;
    }
}

void entity_screen_startup_children(EScreen *entity) {
    const node_t *current = linkedlist_gethead(entity->children);

    while (current) {
        entity_startup((EHeader*)current->data);

        current = current->nextptr;
    }
}
