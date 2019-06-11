#include "font.h"

jo_font *font_get(FontArray *fonts, FontType font_type) {
    return fonts->data[font_type];
}
