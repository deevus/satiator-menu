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

static int * current_page;
static int * current_selection;

// Fonts
static jo_font * FONT_MOS_WHT; 
static jo_font * FONT;

typedef struct
{
    jo_2d_object_attributes     attributes;
    int                         sprite_id;

} character;

static jo_storyboard *storyboard;
static jo_animation  *animation;
static character test;
static character test_strings[200];


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


static int current_index = 0;
static int page_size     = 10;

void draw_list() {

    // char *game_titles[] = {
    //     // Page 1
    //     "Astal",
    //     "Baku Baku",
    //     "Bug",
    //     "Burning Rangers",
    //     "Dark Savior",
    //     "Daytona USA",
    //     "Deep Fear",
    //     "Dragon Force",
    //     "Grandia",
    //     "Guardian Heroes",
    //     // Page 2
    //     "Gungriffon",
    //     "Lunar"
    //     "Magic Knight Rayearth",
    //     "Mortal Kombat",
    //     "Pandemonium",
    //     "Road Rash",
    //     "Sega Rally",
    //     "Shining Force 3",
    //     "Virtua Cop",
    //     "Virtua On"
    // };



    // // int i;
    // // for (i = 0; i < 10; i++) {
    // //     int y_offset = (2 * (i * 1)) + 10;

    // //     jo_printf(12, y_offset, game_titles[i]);

    // // }

    // int i;
    // int vertical_offset_step   = 20;
    // int vertical_offset_origin = -80;
    // int y_offset;

    // for (i = 0; i < 10; i++) {
    //     y_offset = vertical_offset_origin + (i * vertical_offset_step);

    //     // jo_sprite_draw3D(sprite_selector_id, 0, y, 100);

    //     jo_font_printf_centered(FONT_MOS_WHT, 0, y_offset, 0.5f, game_titles_p1[i]);
    //     jo_font_printf_centered(FONT_MOS_WHT, 110, y_offset, 0.25f, "300");
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
    // jo_font_printf_centered(FONT_MOS_WHT, 0, -40, 1.0f, "@ABCDEFGHIJKLMNO");

    // Demo font full mapping
    // jo_font_printf_centered(FONT, 0, 0, 1.0f, "?=%&’,.()*+-/");

    // Example from the sample  
    // jo_font_printf_centered(FONT, 0, 40, 1.0f, "SCORE = %d",  42);

    // Second line
    // jo_font_printf_centered(FONT_MOS_WHT, 0, -40, 1.0f, "0123456789:;<=>?");

    // Third line
    // jo_font_printf_centered(FONT_MOS_WHT, 0, 0, 1.0f, "@ABCDEFGHIJKLMNO");

    // Fourth line
    // jo_font_printf_centered(FONT_MOS_WHT, 0, 40, 1.0f, "PQRSTUVWXYZ[\\]^_");


    // jo_font_printf_centered(FONT_MOS_WHT, 0, 80, 1.0f, "abcdefghijklmno");
    // jo_font_printf_centered(FONT_MOS_WHT, 0, 120, 1.0f, "pqrstuvwxyz");

    // Draw dividers

    // jo_sprite_enable_half_transparency();
    
    jo_sprite_draw3D(sprite_divider_id, 0, -70, 150);
    jo_sprite_draw3D(sprite_divider_id, 0, -50, 150);
    jo_sprite_draw3D(sprite_divider_id, 0, -30, 150);
    jo_sprite_draw3D(sprite_divider_id, 0, -10, 150);
    jo_sprite_draw3D(sprite_divider_id, 0, 10, 150);
    jo_sprite_draw3D(sprite_divider_id, 0, 30, 150);
    jo_sprite_draw3D(sprite_divider_id, 0, 50, 150);
    jo_sprite_draw3D(sprite_divider_id, 0, 70, 150);
    jo_sprite_draw3D(sprite_divider_id, 0, 90, 150);
    // jo_sprite_disable_gouraud_shading();
    // jo_sprite_disable_half_transparency();
}

void update() {
    jo_printf(15, 1, "*Transitions*");

    process_entities(&entity_update);

    // Draw selection sprite
    // Draw a shadow underneath
    // jo_sprite_enable_shadow_filter();
    // jo_sprite_draw3D(sprite_selector_id, 0, 1, 100);
    // jo_sprite_disable_shadow_filter();

    // jo_sprite_draw3D(sprite_selector_id, 0, 0, 100);


    jo_sprite_change_sprite_scale(0.5f);
    
    int i;
    for (i = 0; i < 178; i++) {
        jo_sprite_draw3D2(test_strings[i].sprite_id, test_strings[i].attributes.x, test_strings[i].attributes.y, 200);
        // int *ptr;
        // jo_core_error("starting loop: %d", i);
        // for (ptr = test_strings[i]; *ptr != 0; ptr++) {
            // jo_core_error("Drawing %d - %d - %d", test_strings[i][*ptr].attributes.x, test_strings[i][*ptr].attributes.y, test_strings[i][*ptr].attributes.z);
            // jo_sprite_draw3D(test_strings[i][*ptr].sprite_id, test_strings[i][*ptr].attributes.x, test_strings[i][*ptr].attributes.y, 200); 
        // }

    }

    jo_sprite_restore_sprite_scale();

    // draw_list();
    // jo_sprite_change_sprite_scale(2.0f);
    // jo_sprite_draw3D(test.sprite_id, test.attributes.x, test.attributes.y, 200);
    // jo_sprite_draw3D(test.sprite_id, test.attributes.x, test.attributes.y, 100);
    // animate_page_left();
    // jo_sprite_restore_sprite_scale();

    jo_sprite_change_sprite_scale(0.5f);
    jo_sprite_draw3D(sprite_bumper_left_id, -140, 0, 100);
    jo_sprite_draw3D(sprite_bumper_right_id, 140, 0, 100);
    jo_sprite_change_sprite_scale(1.0f);

    // jo_printf(0, 24, "Polygon count: %d  ", jo_3d_get_polygon_count());
    // jo_printf(0, 26, "Sprite useage: %d  ", jo_sprite_usage_percent());
    // jo_printf(0, 28, "Dynamic memory usage: %d%%  ", jo_memory_usage_percent());
}


void destroy() {
    process_entities(&entity_destroy);
}

// TODO - For some reason font load order makes a difference to how they show up when being used...
void load_new_fonts() {
    
    // Sample font
    // FONT = jo_font_load("FONTS", "FONT.TGA", JO_COLOR_Green, 8, 8, 2, "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ!\"?=%&',.()*+-/");
    
    FONT_MOS_WHT = jo_font_load("FONTS", "MOSWHT.TGA", JO_COLOR_Green, 16, 32, 0, 
        " !\"#$%&`()*+,_./\n0123456789:;<=>?\n@ABCDEFGHIJKLMNO\nPQRSTUVWXYZ[\\]^_\n\'abcdefghijklmno\npqrstuvwxyz{|}~¢"
    );
}

void load_new_assets() {
    load_new_fonts();

    sprite_bumper_left_id  = jo_sprite_add_tga("IMAGES", "L.TGA", JO_COLOR_Green);
    sprite_bumper_right_id = jo_sprite_add_tga("IMAGES", "R.TGA", JO_COLOR_Green);
    sprite_selector_id     = jo_sprite_add_tga("IMAGES", "SELECT.TGA", JO_COLOR_Green);
    sprite_divider_id      = jo_sprite_add_tga("IMAGES", "DIVIDER.TGA", JO_COLOR_Green);
}

static int (*page)(void);

void get_page() {
    char *game_titles[] = {
        // Page 1
        "Astal",
        "Baku Baku",
        "Bug",
        "Burning Rangers",
        "Dark Savior",
        "Daytona USA",
        "Deep Fear",
        "Dragon Force",
        "Grandia",
        "Guardian Heroes",
        // Page 2
        // "Gungriffon",
        // "Lunar"
        // "Magic Knight Rayearth",
        // "Mortal Kombat",
        // "Pandemonium",
        // "Road Rash",
        // "Sega Rally",
        // "Shining Force 3",
        // "Virtua Cop",
        // "Virtua On"
    };

    int i;
    int vertical_offset_step   = 20;
    int vertical_offset_origin = -80;
    int y_offset;

    for (i = 0; i < 10; i++) {
        y_offset = vertical_offset_origin + (i * vertical_offset_step);

        jo_font_printf_centered(FONT_MOS_WHT, 0, y_offset, 0.5f, game_titles[i]);
        jo_font_printf_centered(FONT_MOS_WHT, 110, y_offset, 0.25f, "300");
    }
}

void animate_page_left() {

    // We create a new storyboard for all saw (that means that you can use the same storyboard with multiple object)
    storyboard = jo_storyboard_create(true, false);

    // Now we add a new custom animation (smooth translation + rotation) (that means that you can add multiple animation)
    animation = jo_storyboard_create_animation(storyboard, 0, 0);
    animation->cos_radius = 80;
    // animation->sin_radius = 40;
    animation->translation_speed_x = 2;
    // animation->translation_speed_y = 2;
    // animation->rotation_speed = 10;
    // Now we can animate any object

    // jo_printf(0, 26, "x - %d | y - %d | z - %d", test.attributes.x, test.attributes.y, test.attributes.z);
    int i;
    for (i = 0; i < 178; i++) {
        jo_storyboard_add_object(storyboard, &test_strings[i]);
    }
        
    // jo_storyboard_add_object(storyboard, FONT_MOS_WHT->lookup_table[FONT_MOS_WHT->start_ascii]);        
    // jo_storyboard_add_object(storyboard, &saws[1]);
    // Next step in my_draw()

}

void animate_page_right() {

}

void animate_page_up() {

}

void animate_page_down() {

}

void input() {
    // KeyEventMessageData data = {
    //     JO_KEY_A,
    //     jo_is_pad1_key_pressed(JO_KEY_A),
    // };

    // Message message;
    // message.type = MT_KEY_EVENT;
    // message.data = &data;

    // message_event_dispatch(message);

    if (jo_is_pad1_key_pressed(JO_KEY_L)) {
        // jo_storyboard_play(&storyboard);
    }

    if (jo_is_pad1_key_pressed(JO_KEY_R)) {
        
    }
}

void jo_main(void) {
    jo_core_init(JO_COLOR_RGB(12, 13, 15));
    page = get_page;

    load();
    load_new_assets();

    char *game_titles[] = {
        // Page 1
        "Astal",
        "Baku Baku",
        "Bug",
        "Burning Rangers",
        "Dark Savior",
        "Daytona USA",
        "Deep Fear",
        "Dragon Force",
        "Grandia",
        "Guardian Heroes",
    };

    
    int i;
    int string_index = 0;
    for (i = 0; i < 10; i++) {
        int j = 0;
        while(*game_titles[i]) {
            // jo_core_error("Char: %c", *game_titles[i]);s
            character c;
            c.sprite_id    = FONT_MOS_WHT->lookup_table[*game_titles[i] - FONT_MOS_WHT->start_ascii];
            c.attributes.x = 0 + (j * 16);  // character spacing
            c.attributes.y = 0 + (i * 32);  // character vertical spacing
            c.attributes.z = 100;
            
            test_strings[string_index] = c;

            j++;
            string_index++;
            ++game_titles[i];
        }
    }

    // jo_core_error("x: %d | y: %d", test_strings[0].attributes.x, test_strings[0].attributes.y);



    // test.sprite_id = FONT_MOS_WHT->lookup_table[FONT_MOS_WHT->start_ascii + 5];
    // test.sprite_id = jo_sprite_add_tga(IMAGE_DIR, "L.TGA", JO_COLOR_Green);
    // test.attributes.x = 50;
    // test.attributes.y = 50;
    // test.attributes.z = 100;

    startup();

    // TODO - dont forget to turn this back on
    animate_page_left();

    jo_core_add_callback(input);
    jo_core_add_callback(update);

    // does this get called?
    signal(SIGINT, destroy);

    jo_core_run();
}
