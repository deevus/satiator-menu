#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"
#include <stdbool.h>

typedef struct {
    node_t sentinel;
    int size;
    bool circular;
} linkedlist_t;

void linkedlist_init(linkedlist_t *ll);

node_t *linkedlist_insert(linkedlist_t *ll, const void *data);

void linkedlist_remove(linkedlist_t *ll, const void *data);

const node_t *linkedlist_gethead(const linkedlist_t *ll);

const node_t *linkedlist_gettail(const linkedlist_t *ll);

bool linkedlist_isempty(const linkedlist_t *ll);

const int linkedlist_getsize(const linkedlist_t *ll);

void linkedlist_destroy(linkedlist_t *ll);

#endif /* LINKEDLIST_H */
