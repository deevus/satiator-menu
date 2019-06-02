#ifndef ENTITY_H
#define ENTITY_H

#include <stdint.h>

typedef enum {
    ET_SCREEN,
    ET_DRAW,
    ET_COUNT,
} EType;

typedef struct {
    uint32_t id;
    EType type;
    uint8_t position[3];
} EHeader;

void entity_draw(EHeader *header);

void entity_free(EHeader *header);

EHeader *entity_create(EType type);

#endif
