#include "s_font.h"

#include <jo/jo.h>
#include <stdlib.h>

#define FONT_DIR "FONTS"

FontArray *system_font_init() {
    FontArray *fonts = (FontArray *)malloc(sizeof(FontArray) + sizeof(jo_font *) * FT_COUNT);

    fonts->size = FT_COUNT;

    fonts->data[FT_MOSWHT] = jo_font_load(FONT_DIR, "MOSWHT.TGA", JO_COLOR_Green, 16, 32, 0, " !\"#$%&`()*+,_./\n0123456789:;<=>?\n@ABCDEFGHIJKLMNO\nPQRSTUVWXYZ[\\]^_\n\'abcdefghijklmno\npqrstuvwxyz{|}~¢");

    return fonts;
}
