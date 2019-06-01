#ifndef ENTITY_H
#define ENTITY_H

#include <stdint.h>

typedef enum {
    ET_MENU,
    ET_GAME_BROWSER,
    ET_SAVE_MANAGER,
    ET_COUNT,
} EType;

typedef struct {
    void *id;
    char *name;
    EType type;
    void *next;
    void *prev;
} EHeader;

void entity_draw(EHeader *header);

void entity_free(EHeader *header);

EHeader *entity_create(EType type);

#endif
