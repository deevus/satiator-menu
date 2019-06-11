#include "c_text.h"

TextComponent *component_text_create(char *value, FontType font_type, bool centered, float scale) {
    TextComponent *text = (TextComponent *)malloc(sizeof(TextComponent));
    ComponentHeader header = {CT_TEXT, false};

    text->header    = header;
    text->font_type = font_type;
    text->centered  = centered;
    text->value     = value;
    text->scale     = scale;

    return text;
}
