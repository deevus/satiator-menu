#ifndef ENTITY_H
#define ENTITY_H
#endif

#include <stdint.h>

typedef enum {
    ET_GAME_BROWSER,
    ET_SAVE_MANAGER,
    ET_COUNT,
} EType;

typedef struct {
    uint8_t id;
    EType type;
    void *next;
    void *prev;
} EHeader;

typedef struct {
    EHeader header;
} EGameBrowser;

typedef struct {
    EHeader header;
} ESaveManager;
