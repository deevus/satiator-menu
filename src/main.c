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
#include "entity.h"
#include "node.h"
#include "linkedlist.h"
#include "screen_gamebrowser.h"
#include <stdlib.h>
#include <signal.h>
#include "message.h"
#include "message_type.h"

#define IMAGE_DIR "IMAGES"

extern linkedlist_t *event_subscribers;

linkedlist_t *entities;

void load() {
    entities = (linkedlist_t *)malloc(sizeof(linkedlist_t));
    linkedlist_init(entities);
    linkedlist_insert(entities, screen_gamebrowser_create());
}

static void process_entities(void (*callback)(EHeader*)) {
    node_t *current = linkedlist_gethead(entities);

    while (current) {
        EHeader *entity = (EHeader*)current->data;

        callback(entity);

        current = current->nextptr;
    }
}

void startup() {
    process_entities(&entity_startup);
}

void update() {
    process_entities(&entity_update);
}

void destroy() {
    process_entities(&entity_destroy);
}

void input() {
    if (jo_is_pad1_key_pressed(JO_KEY_A)) {
        KeyEventMessageData data = {
            JO_KEY_A,
            true,
        };

        Message message;
        message.type = MT_KEY_EVENT;
        message.data = &data;

        jo_printf(5, 6, "Dispatching event");

        message_event_dispatch(message);
    } else {
        jo_printf(5, 6, "                          ");
    }
}

void jo_main(void) {
    jo_core_init(JO_COLOR_RGB(12, 13, 15));

    load();

    startup();

    jo_core_add_callback(input);
    jo_core_add_callback(update);

    // does this get called?
    signal(SIGINT, destroy);

    jo_core_run();
}
