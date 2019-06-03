#ifndef MESSAGE_H
#define MESSAGE_H

#include <stdint.h>
#include "linkedlist.h"

typedef enum {
    MT_KEY_EVENT,
    MT_COUNT,
} MessageType;

typedef struct {
    MessageType type;
    void *data;
} Message;

typedef void Subscriber;
typedef void (*MessageHandler)(const Subscriber *, const Message *);

typedef struct {
    Subscriber *subscriber;
    MessageHandler *handler;
} Subscription;

typedef struct {
    MessageType type;
    linkedlist_t *subscribers;
} SubscriptionList;

void message_event_subscribe(void *subscriber, const MessageType type, MessageHandler *handler);

void message_event_unsubscribe(const void *subscriber, const MessageType type);

void message_event_dispatch(const Message message);

#endif
