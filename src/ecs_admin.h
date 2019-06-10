#ifndef __ECS_ADMIN_H
#define __ECS_ADMIN_H

#include <stdint.h>
#include "entity.h"
#include "component.h"

typedef struct {
    EntityArray *entities;
    ComponentArray *components;
} ECSAdmin;

ECSAdmin *ecs_admin_create();

void ecs_admin_update(ECSAdmin *admin);

void ecs_admin_free(ECSAdmin *admin);

#endif
