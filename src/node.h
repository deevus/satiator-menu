#ifndef NODE_H
#define NODE_H

typedef struct Node node_t;
struct Node {
  const void *data;
  node_t *nextptr;
  node_t *prevptr;
};

void node_init(node_t *node, const void *data);

#endif /* NODE_H */
