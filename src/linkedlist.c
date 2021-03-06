#include "linkedlist.h"
#include <stdlib.h>
#include "jo/jo.h"

void linkedlist_init(linkedlist_t *ll) {
    //init struct vars
    node_init(&ll->sentinel, NULL);

    ll->sentinel.nextptr = ll->sentinel.prevptr = &ll->sentinel;

    ll->size = 0;
}

node_t *linkedlist_insert(linkedlist_t *ll, const void *data) {
    node_t *temp = malloc(sizeof(node_t));
    node_init(temp, data);

    //set new tail
    ll->sentinel.prevptr->nextptr = temp;
    temp->prevptr = ll->sentinel.prevptr;
    temp->nextptr = &ll->sentinel;

    ll->sentinel.prevptr = temp;
    ll->size++;

    return temp;
}

const node_t *linkedlist_gethead(const linkedlist_t *ll) {
    if (ll->size > 0) {
        return ll->sentinel.nextptr;
    }

    return NULL;
}

const node_t *linkedlist_gettail(const linkedlist_t *ll) {
    if (ll->size > 0) {
        return ll->sentinel.prevptr;
    }

    return NULL;
}

const node_t *linkedlist_find_node(const linkedlist_t *ll, void *data) {
    const node_t *curr = ll->sentinel.nextptr;

    while (curr) {
        if (data == curr->data) {
            return curr;
        }

        curr = linkedlist_next(ll, curr);
    }

    return NULL;
}

void linkedlist_remove(linkedlist_t *ll, const void *data) {
    //find node
    const node_t *node = linkedlist_find_node(ll, data);
    if (!node) {
        jo_core_error("Node not found.\r\n");
        return;
    }

    node_t *prev = node->prevptr;
    node_t *next = node->nextptr;

    if (prev != NULL && next != NULL) {
        //point surrounding nodes at each other
        prev->nextptr = next;
        next->prevptr = prev;
    } else if (prev != NULL) {
        //node was tail
        prev->nextptr = &ll->sentinel;
        ll->sentinel.prevptr = prev;
    } else {
        //node was head
        next->prevptr = &ll->sentinel;
        ll->sentinel.nextptr = next;
    }

    free(node);
    ll->size--;
}

const node_t *linkedlist_next(const linkedlist_t *ll, const node_t *current) {
    const node_t *next = current->nextptr;

    // if next node is the tail
    if (next == &ll->sentinel) {
        return NULL;
    }

    return next;
}

bool linkedlist_isempty(const linkedlist_t *ll) {
    return ll->size == 0;
}

const int linkedlist_getsize(const linkedlist_t *ll) {
    return ll->size;
}

void linkedlist_destroy(linkedlist_t *ll) {
    node_t *next;
    node_t *curr = ll->sentinel.nextptr;

    for (int i = 0; i < ll->size; ++i)
    {
        //get next node
        next = curr->nextptr;

        //free this one
        if (curr) {
            free(curr);
        }

        //get next
        curr = next;
    }
}
