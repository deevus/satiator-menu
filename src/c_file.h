#ifndef _C_FILE_H
#define _C_FILE_H

#include "component.h"

typedef struct {
    ComponentHeader header;
    const char *directory;
    const char *filename;
} FileComponent;

FileComponent *component_file_create(const char *directory, const char *filename);

#endif
