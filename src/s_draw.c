#include "s_draw.h"
#include "component.h"
#include "c_background.h"
#include "c_transform.h"
#include <jo/jo.h>

void system_draw_process(EntityArray *entities, uint16_t delta_ticks) {
    // backgrounds
    for (size_t i = 0; i < entities->size; i++) {
        ComponentArray *components = entities->data[i].components;

        if (components->types & (CT_BACKGROUND | CT_TRANSFORM)) {
            BackgroundComponent *background        = (BackgroundComponent *)component_find(components, CT_BACKGROUND);
            TransformComponent *transform = (TransformComponent *)component_find(components, CT_TRANSFORM);

            jo_pos2D *position = &transform->position;
            jo_sprite_draw3D(background->image_id, position->x, position->y, 500);
        }
    }

    // sprites

    // foregrounds
}
