#include "c_background.h"
#include <stdlib.h>

const Background *component_background_create(char *directory, char *filename) {
    Background *background = (Background *)malloc(sizeof(Background));

    ComponentHeader header = {CT_BACKGROUND};
    background->header     = header;
    background->directory  = directory;
    background->filename   = filename;

    return background;
}
