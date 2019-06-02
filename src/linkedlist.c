#include "linkedlist.h"
#include <stdlib.h>
#include <stdio.h>
#include "jo/jo.h"

void linkedlist_init(linkedlist_t *ll) {
    //init struct vars
    node_init(&ll->sentinel, NULL);
    ll->sentinel.nextptr = ll->sentinel.prevptr = &ll->sentinel;
    ll->size = 0;
}

void linkedlist_insert(linkedlist_t *ll, const void *data) {
    node_t *temp = malloc(sizeof(node_t));
    node_init(temp, data);

    //set new tail
    ll->sentinel.prevptr->nextptr = temp;
    temp->prevptr = ll->sentinel.prevptr;
    temp->nextptr = &ll->sentinel;
    ll->sentinel.prevptr = temp;

    ll->size++;
}

const void *linkedlist_gethead(const linkedlist_t *ll) {
    const void *data = NULL;
    node_t *head = ll->sentinel.nextptr;
    if (head != NULL) data = head->data;
    return data;
}

const void *linkedlist_gettail(const linkedlist_t *ll) {
    const void *data = NULL;
    node_t *tail = ll->sentinel.prevptr;
    if (tail != NULL) data = tail->data;
    return data;
}

static node_t *find_node(const linkedlist_t *ll, const void *data) {
    node_t *curr = ll->sentinel.nextptr;
    while (curr) {
        if (data == curr->data) {
            return curr;
        }

        curr = curr->nextptr;
    }

    return NULL;
}

void linkedlist_remove(linkedlist_t *ll, const void *data) {
    //find node
    node_t *node = find_node(ll, data);
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

bool linkedlist_isempty(const linkedlist_t *ll) {
    return ll->size == 0;
}

const int linkedlist_getsize(const linkedlist_t *ll) {
    return ll->size;
}

void linkedlist_destroy(linkedlist_t *ll) {
    node_t *next, *curr = ll->sentinel.nextptr;
    for (int i = 0; i < ll->size; ++i)
    {
        //get next node
        next = curr->nextptr;

        //free this one
        if (curr)
            free(curr);

        //get next
        curr = next;
    }
}
