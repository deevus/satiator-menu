#include <stdlib.h>
#include "entity.h"

void entity_draw(EHeader *header) {
    switch (header->type) {
        default:
            break;
    }
}

void entity_free(EHeader *header) {
    switch (header->type) {
        default:
            break;
    }
}

EHeader *entity_create(EType type) {
    switch (type) {
        default:
            return NULL;
    }
}
