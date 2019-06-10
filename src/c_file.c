#include "c_file.h"
#include <stdlib.h>

FileComponent *component_file_create(const char *directory, const char *filename) {
    FileComponent *file = (FileComponent *)malloc(sizeof(FileComponent));

    ComponentHeader header = {CT_FILE, false};
    file->header           = header;
    file->directory        = directory;
    file->filename         = filename;

    return file;
}
