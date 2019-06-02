#ifndef ENTITY_H
#define ENTITY_H

#include <stdint.h>
#include "linkedlist.h"
#include "jo/jo.h"
#include "message.h"

typedef enum {
    ET_SCREEN,
    ET_BACKGROUND,
    ET_TEXT,
    ET_COUNT,
} EType;

typedef struct {
    uint32_t id;
    EType type;
    jo_pos3D position;
    void *startup;
    void *update;
    void *destroy;
    void *receive_message;
} EHeader;

typedef struct {
    EHeader header;
    linkedlist_t *children;
} EScreen;

typedef struct {
    EHeader header;
    char* directory;
    char* name;
    jo_color transparent_color;
    int sprite_id;
} EBackground;

typedef struct {
    EHeader header;
    jo_font font;
    char* value;
} EText;

EHeader *entity_create(EType type);

void entity_startup(EHeader *entity);

void entity_update(EHeader *entity);

void entity_destroy(EHeader *entity);

void entity_send_message(const Message *message, const linkedlist_t *to, const void *from);

void entity_receive_message(EHeader *entity, const Message *message, const void *source);

void entity_screen_update_children(EScreen *entity);

void entity_screen_startup_children(EScreen *entity);

#endif
