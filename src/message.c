#include "message.h"
#include "linkedlist.h"
#include <stdlib.h>
#include "jo/jo.h"

linkedlist_t *event_subscribers = NULL;

static linkedlist_t *subscribers_for_type(MessageType type) {
    if (event_subscribers == NULL) {
        event_subscribers = (linkedlist_t *)malloc(sizeof(linkedlist_t));
        linkedlist_init(event_subscribers);
    }

    const node_t *node = linkedlist_gethead(event_subscribers);

    jo_core_error("Node: %x", node);

    SubscriptionList *subscription_list = NULL;

    while (node) {
        SubscriptionList *temp = (SubscriptionList *)node->data;

        if (subscription_list->type == type) {
            subscription_list = temp;
            break;
        }

        node = node->nextptr;
    }

    if (subscription_list == NULL) {
        subscription_list = (SubscriptionList *)malloc(sizeof(SubscriptionList));

        linkedlist_t *subscribers = (linkedlist_t *)malloc(sizeof(linkedlist_t));
        linkedlist_init(subscribers);
        subscription_list->subscribers = subscribers;

        linkedlist_insert(event_subscribers, subscription_list);
    }

    linkedlist_t *subscribers = subscription_list->subscribers;

    return subscribers;
}

void message_event_subscribe(void *subscriber, const MessageType type, MessageHandler *handler) {
    Subscription *subscription = (Subscription *)malloc(sizeof(Subscription));
    subscription->subscriber   = subscriber;
    subscription->handler      = handler;

    linkedlist_insert(subscribers_for_type(type), subscription);
}

void message_event_unsubscribe(const void *subscriber, const MessageType type) {
    linkedlist_t *subscriptions = subscribers_for_type(type);

    const node_t *current = linkedlist_gethead(subscriptions);

    while (current) {
        Subscription *subscription = (Subscription *)current->data;

        if (subscription->subscriber == subscriber) {
            linkedlist_remove(subscriptions, subscription);
            break;
        }

        current = current->nextptr;
    }
}

void message_event_dispatch(const Message message) {
    const node_t *current = linkedlist_gethead(subscribers_for_type(message.type));

    while (current) {
        Subscription *subscription = (Subscription *)current->data;
        MessageHandler handler     = *subscription->handler;

        if (handler) handler(subscription->subscriber, &message);

        current = current->nextptr;
    }
}
