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
#include "xbuttonmap.h"

#define IMAGE_DIR "IMAGES"

static int anim_id;

void Draw(void) {
    jo_sprite_draw3D2(jo_get_anim_sprite(anim_id), 160, 120, 450);

    if (jo_is_sprite_anim_stopped(anim_id)) {
        jo_start_sprite_anim_loop(anim_id);
    }
}

int LoadXButton() {
    return jo_sprite_add_bin_tileset(IMAGE_DIR, "XBUTTON.BIN", JO_COLOR_Green, XButtonMap, JO_TILE_COUNT(XButtonMap));
}

void LoadBackground() {
    jo_img bg;

    jo_tga_loader(&bg, IMAGE_DIR, "MENUBG.TGA", JO_COLOR_Transparent);
    jo_set_background_sprite(&bg, 0, 0);
    jo_free_img(&bg);
}

void jo_main(void) {
    jo_core_init(JO_COLOR_Black);

    /*InitBorder();*/
    LoadBackground();

    anim_id = jo_create_sprite_anim(LoadXButton(), JO_TILE_COUNT(XButtonMap), 8);

    jo_core_add_callback(Draw);
    jo_core_run();
}
