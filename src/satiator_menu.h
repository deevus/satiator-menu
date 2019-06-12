#ifndef __SATIATOR_MENU_H
#define __SATIATOR_MENU_H

#include "entity.h"

typedef enum {
    SMC_BACKGROUND,
    SMC_BORDER,
    SMC_MENU,
    SMC_COUNT,
} SatiatorMenuComponents;

const EntityArray *satiator_menu_create();

#endif
