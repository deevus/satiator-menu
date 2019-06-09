/*
** Jo Sega Saturn Engine
** Copyright (c) 2012-2018, Johannes Fetz (johannesfetz@gmail.com)
** All rights reserved.
**
** Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are met:
**     * Redistributions of source code must retain the above copyright
**       notice, this list of conditions and the following disclaimer.
**     * Redistributions in binary form must reproduce the above copyright
**       notice, this list of conditions and the following disclaimer in the
**       documentation and/or other materials provided with the distribution.
**     * Neither the name of the Johannes Fetz nor the
**       names of its contributors may be used to endorse or promote products
**       derived from this software without specific prior written permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
** ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
** WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
** DISCLAIMED. IN NO EVENT SHALL Johannes Fetz BE LIABLE FOR ANY
** DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
** (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
** LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
** ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
** SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#include <jo/jo.h>
#include "entity.h"
#include "node.h"
#include "linkedlist.h"
#include "screen_gamebrowser.h"
#include <stdlib.h>
#include <signal.h>
#include "message.h"
#include "message_type.h"

#define IMAGE_DIR "IMAGES"
#define FONT_DIR  "FONTS"

extern linkedlist_t *event_subscribers;

linkedlist_t *entities;

// Assets
static int sprite_bumper_left_id;
static int sprite_bumper_right_id;
static int sprite_selector_id;
static int sprite_divider_id;

// Fonts
static jo_font * FONT_MOS_WHT; 
static jo_font * FONT;
// static jo_font * FONT_MOS_BLK;
// static jo_font * FONT_MOS_DGY;

void load() {
    entities = (linkedlist_t *)malloc(sizeof(linkedlist_t));
    linkedlist_init(entities);
    linkedlist_insert(entities, screen_gamebrowser_create());
}

static void process_entities(void (*callback)(EHeader*)) {
    node_t *current = linkedlist_gethead(entities);

    while (current) {
        EHeader *entity = (EHeader*)current->data;

        callback(entity);

        current = linkedlist_next(entities, current);
    }
}

void startup() {
    process_entities(&entity_startup);
}


void draw_list() {
    
    char *game_titles[] = {
        "Astal",
        "Baku Baku",
        "Bug",
        "Burning Rangers",
        "Dark Savior",
        "Daytona USA",
        "Deep Fear",
        "Dragon Force",
        "Grandia",
        "Gungriffon"
    };


    // int i;
    // for (i = 0; i < 10; i++) {
    //     int y_offset = (2 * (i * 1)) + 10;

    //     jo_printf(12, y_offset, game_titles[i]);

    // }

    // int i;
    // int vertical_offset_step   = 20;
    // int vertical_offset_origin = -80;
    // int y_offset;

    // for (i = 0; i < 10; i++) {
    //     y_offset = vertical_offset_origin + (i * vertical_offset_step);

    //     // jo_sprite_draw3D(sprite_selector_id, 0, y, 100);

    //     jo_font_printf_centered(FONT_MOS_WHT, 0, y_offset, 1.0f, game_titles[i]);
    //     jo_font_printf_centered(FONT_MOS_WHT, 0, y_offset, 1.0f, "300");
    // }

    // Static games list
    // jo_font_printf_centered(FONT_LIST_WHT, 0, -80, 0.5f, "Astal");
    // jo_font_printf_centered(FONT_LIST_WHT, 125, -80, 0.5f, "300");
    // jo_font_printf_centered(FONT_LIST_WHT, 0, -60, 0.5f, "Baku Baku");
    // jo_font_printf_centered(FONT_LIST_WHT, 125, -60, 0.5f, "300");
    // jo_font_printf_centered(FONT_LIST_WHT, 0, -40, 0.5f, "Bug");
    // jo_font_printf_centered(FONT_LIST_WHT, 125, -40, 0.5f, "300");
    // jo_font_printf_centered(FONT_LIST_WHT, 0, -20, 0.5f, "Burning Rangers");
    // jo_font_printf_centered(FONT_LIST_WHT, 125, -20, 0.5f, "300");

    // Handles characters from first line of mapping
    // jo_font_printf_centered(FONT_MOS_WHT, 0, -80, 1.0f, "! !\"#$%&`()*+,_./&!");
    jo_font_printf_centered(FONT, 0, 0, 1.0f, "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ!\"?=%&’,.()*+-/");

    // Second line
    // jo_font_printf_centered(FONT_MOS_WHT, 0, -40, 1.0f, "0123456789:;<=>?");

    // Third line
    // jo_font_printf_centered(FONT_MOS_WHT, 0, 0, 1.0f, "@ABCDEFGHIJKLMNO");

    // Fourth line
    // jo_font_printf_centered(FONT_MOS_WHT, 0, 40, 1.0f, "PQRSTUVWXYZ[\\]^_");


    // jo_font_printf_centered(FONT_MOS_WHT, 0, 80, 1.0f, "abcdefghijklmno");
    // jo_font_printf_centered(FONT_MOS_WHT, 0, 120, 1.0f, "pqrstuvwxyz");

    // Draw dividers
    // jo_sprite_draw3D(sprite_divider_id, 0, -70, 150);
    // jo_sprite_draw3D(sprite_divider_id, 0, -50, 150);
    // jo_sprite_draw3D(sprite_divider_id, 0, -30, 150);
    // jo_sprite_draw3D(sprite_divider_id, 0, -10, 150);
    // jo_sprite_draw3D(sprite_divider_id, 0, 10, 150);
    // jo_sprite_draw3D(sprite_divider_id, 0, 30, 150);
    // jo_sprite_draw3D(sprite_divider_id, 0, 50, 150);
    // jo_sprite_draw3D(sprite_divider_id, 0, 70, 150);
}

void update() {

    process_entities(&entity_update);
    jo_sprite_draw3D(sprite_bumper_left_id, -140, 0, 100);
    jo_sprite_draw3D(sprite_bumper_right_id, 140, 0, 100);


    // Draw selection sprite
    // Draw a shadow underneath
    jo_sprite_enable_shadow_filter();
    jo_sprite_draw3D(sprite_selector_id, 0, 1, 100);
    jo_sprite_disable_shadow_filter();

    jo_sprite_draw3D(sprite_selector_id, 0, 0, 100);


    draw_list();
    

    jo_printf(0, 28, "Polygon count: %d  ", jo_3d_get_polygon_count());
}


void destroy() {
    process_entities(&entity_destroy);
}

void input() {
    KeyEventMessageData data = {
        JO_KEY_A,
        jo_is_pad1_key_pressed(JO_KEY_A),
    };

    Message message;
    message.type = MT_KEY_EVENT;
    message.data = &data;

    message_event_dispatch(message);
}

void load_new_fonts() {
    FONT_MOS_WHT = jo_font_load("FONTS", "MOSWHT.TGA", JO_COLOR_Green, 16, 32, 0, 
        " !\"#$%&`()*+,_./\n0123456789:;<=>?\n@ABCDEFGHIJKLMNO\nPQRSTUVWXYZ[\\]^_\n\'abcdefghijklmno\npqrstuvwxyz{|}~¢"
    );

    FONT = jo_font_load("FONTS", "FONT.TGA", JO_COLOR_Green, 8, 8, 2, 
        "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ!\"?=%&’,.()*+-/"
    );
}

void load_new_assets() {
    load_new_fonts();

    sprite_bumper_left_id  = jo_sprite_add_tga("IMAGES", "L.TGA", JO_COLOR_Green);
    sprite_bumper_right_id = jo_sprite_add_tga("IMAGES", "R.TGA", JO_COLOR_Green);
    sprite_selector_id     = jo_sprite_add_tga("IMAGES", "SELECT.TGA", JO_COLOR_Green);
    sprite_divider_id      = jo_sprite_add_tga("IMAGES", "DIVIDER.TGA", JO_COLOR_Green);
}

void jo_main(void) {
    jo_core_init(JO_COLOR_RGB(12, 13, 15));

    load();
    load_new_assets();

    startup();

    jo_core_add_callback(input);
    jo_core_add_callback(update);

    // does this get called?
    signal(SIGINT, destroy);

    jo_core_run();
}
