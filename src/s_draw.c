#include "s_draw.h"

#include <jo/jo.h>

#include "component.h"
#include "c_file.h"
#include "c_image.h"
#include "c_transform.h"
#include "c_text.h"

#include "bst.h"
#include "font.h"

typedef struct {
    ImageComponent *image;
    TransformComponent *transform;
} ImageTuple;

static void draw_image_tuple(ImageTuple *tuple) {
    jo_sprite_draw3D(
        tuple->image->image_id,
        tuple->transform->position.x,
        tuple->transform->position.y,
        tuple->transform->position.z
    );
}

static void draw_image_tuples(tree_node_t *node) {
    for (size_t i = 0; i < node->size; i++) {
        draw_image_tuple((ImageTuple *)node->data[i]);
    }
}

void system_draw_process(EntityArray *entities, FontArray *fonts, uint16_t delta_ticks) {
    tree_node_t *bst = NULL;

    for (size_t i = 0; i < entities->size; i++) {
        ComponentArray *components = entities->data[i]->components;

        if ((components->types & (CT_IMAGE | CT_TRANSFORM)) == (CT_IMAGE | CT_TRANSFORM)) {
            ImageComponent *image         = (ImageComponent *)component_find(components, CT_IMAGE);
            TransformComponent *transform = (TransformComponent *)component_find(components, CT_TRANSFORM);

            Position position = transform->position;

            ImageTuple tuple = {image, transform};
            bst = bst_insert(bst, position.z, &tuple);
        }

        if ((components->types & (CT_TEXT | CT_TRANSFORM)) == (CT_TEXT | CT_TRANSFORM)) {
            TextComponent *text           = (TextComponent *)component_find(components, CT_TEXT);
            TransformComponent *transform = (TransformComponent *)component_find(components, CT_TRANSFORM);

            Position position = transform->position;
            jo_font *font = font_get(fonts, text->font_type);

            if (text->centered) {
                jo_font_print_centered(font, position.x, position.y, text->scale, text->value);
            } else {
                jo_font_print(font, position.x, position.y, text->scale, text->value);
            }
        }
    }

    bst_traverse(bst, &draw_image_tuples);

    bst_free(bst);
}
