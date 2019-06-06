#ifndef __ECS_ADMIN_H
#define __ECS_ADMIN_H

#include <stdint.h>
#include "entity.h"
#include "component.h"

typedef struct {
    Entity entities[63];
    ComponentHeader* components[255];
} ECSAdmin;

#endif
