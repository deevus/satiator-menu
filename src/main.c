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
#include "images.h"

#define IMAGE_DIR "IMAGES"

void LoadBorder()
{
    jo_img_8bits img;

    // For JO_COLOR_RGB(r, g, b) each component value (R, G and B) goes from 0 to 63
    // Colors r, g, b are 5 bit
    jo_set_palette_register(0xBB, JO_COLOR_Gray);

    img.data   = border_main;
    img.width  = 320;
    img.height = 240;

    jo_sprite_add_8bits_image(&img);    
}

void DrawBorder(void) {
    LoadBorder();
    jo_sprite_draw3D(0, 0, 0, 500);
}


void DrawBackground(void) {
    jo_img checker_board;

    jo_tga_loader(&checker_board, IMAGE_DIR, "CHECK.TGA", JO_COLOR_Green);
    jo_set_background_sprite(&checker_board, 0, 0);
    jo_free_img(&checker_board);
}

void Draw(void) {
   DrawBackground();
   DrawBorder();
}

void jo_main(void) {
    jo_core_init(JO_COLOR_RGB(12,13,15));

    jo_core_add_callback(Draw);
    jo_core_run();
}
