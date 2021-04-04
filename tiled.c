//
// Created by lowrider on 2021-03-22.
//

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tiled.h"

void add_layers(Tile_Map *tm, JSON_Data *jobj_root);

#define STREQ(str1, str2) strcmp(str1, str2) == 0

Tile_Map *tiled_populate_from_json(JSON_Data *root) {
    JSON_Data *curr;
    Tile_Map *tm;
    if (root == NULL) {
        printf("ERROR: root is NULL\n");
        exit(1);
    }
    tm = malloc(sizeof(Tile_Map));
    for (curr = root; curr != NULL; curr = curr->next) {
        char *key = curr->key;
        void *value = curr->value;
        if (STREQ(key, "height")) {
            tm->height = *(int *) value;
        } else if (STREQ(key, "width")) {
            tm->width = *(int *) value;
        } else if (STREQ(key, "tileheight")) {
            tm->tile_height = *(int *) value;
        } else if (STREQ(key, "tilewidth")) {
            tm->tile_width = *(int *) value;
        } else if (STREQ(key, "layers")) {
            // Linked list of json objects found
            add_layers(tm, (JSON_Data *) value);
        }
    }
    return tm;
}

void add_layers(Tile_Map *tm, JSON_Data *jobj_root) {
    Tile_Layer *tl_root = malloc(sizeof(Tile_Layer));
    JSON_Data *jobj_curr;
    Tile_Layer *tl_curr;

    for (jobj_curr = jobj_root, tl_curr = tl_root; jobj_curr != NULL; jobj_curr = jobj_curr->next) {
        JSON_Data *curr_layer;
        for (curr_layer = (JSON_Data *) jobj_curr->value; curr_layer != NULL; curr_layer = curr_layer->next) {
            char* key = curr_layer->key;
            void* value = curr_layer->value;

            if (STREQ(key, "objects")) {
//            jobj_root = jobj_root->next;
//            continue;
            } else if (STREQ(key, "data")) {
//            root_tl->jobj_root =
            } else if (STREQ(key, "height")) {
                tl_curr->height = *(int *) value;
            } else if (STREQ(key, "id")) {
                tl_curr->id = *(int *) value;
            } else if (STREQ(key, "name")) {
                tl_curr->name = (char *) value;
            } else if (STREQ(key, "type")) {
                tl_curr->type = (char *) value;
            } else if (STREQ(key, "visible")) {
                tl_curr->visible = *(u_char *) value;
            } else if (STREQ(key, "width")) {
                tl_curr->width = *(int *) value;
            } else if (STREQ(key, "x")) {
                tl_curr->x = *(int *) value;
            } else if (STREQ(key, "y")) {
                tl_curr->y = *(int *) value;
            }
        }

        if (jobj_curr->next == NULL) {
            tl_curr->next = NULL;
            continue;
        }

        tl_curr->next = malloc(sizeof(Tile_Layer));
        tl_curr = tl_curr->next;
    }
    tm->layers = tl_root;
}
