#ifndef __ECS_ADMIN_H
#define __ECS_ADMIN_H

#include <stdint.h>
#include <jo/jo.h>

#include "entity.h"
#include "component.h"
#include "font.h"

typedef struct {
    EntityArray *entities;
    FontArray *fonts;
} ECSAdmin;

ECSAdmin *ecs_admin_create();

void ecs_admin_update(ECSAdmin *admin);

void ecs_admin_free(ECSAdmin *admin);

#endif
