#ifndef MESSAGE_TYPE_H
#define MESSAGE_TYPE_H

#include "jo/jo.h"
#include <stdbool.h>

typedef struct {
    jo_gamepad_keys key;
    bool pressed;

} KeyEventMessageData;

#endif
