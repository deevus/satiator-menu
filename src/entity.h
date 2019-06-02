#ifndef ENTITY_H
#define ENTITY_H

#include <stdint.h>
#include "linkedlist.h"
#include "jo/jo.h"

typedef enum {
    ET_SCREEN,
    ET_TEXT,
    ET_COUNT,
} EType;

typedef struct {
    uint32_t id;
    EType type;
    uint8_t position[3];
    void *startup;
    void *update;
} EHeader;

typedef struct {
    EHeader header;
    linkedlist_t children;
} EScreen;

typedef struct {
    EHeader header;
    jo_font font;
    char* value;
} EText;

EHeader *entity_create(EType type);

void entity_startup(EHeader *entity);

void entity_update(EHeader *entity);

#endif
