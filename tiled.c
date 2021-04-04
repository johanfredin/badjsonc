//
// Created by lowrider on 2021-03-22.
//

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tiled.h"

void add_layer(Tile_Map *pMap, JSON_Data *data);

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
            add_layer(tm, (JSON_Data *) value);
        }
    }
    return tm;
}

void add_layer(Tile_Map *tm, JSON_Data *data) {
    Tile_Layer *root_tl = malloc(sizeof(Tile_Layer));;
    Tile_Layer *curr_tl;
    for (curr_tl = root_tl; data != NULL; data = data->next) {

        char *key = data->key;
        void *value = data->value;

        if (STREQ(key, "color")) {
            data = data->next;
            continue;
        }

        if (STREQ(key, "data")) {
//            root_tl->data =
        } else if (STREQ(key, "height")) {
            curr_tl->height = *(int *) value;
        } else if (STREQ(key, "id")) {
            curr_tl->id = *(int *) value;
        } else if (STREQ(key, "name")) {
            curr_tl->name = (char *) value;
        } else if (STREQ(key, "type")) {
            curr_tl->type = (char *) value;
        } else if (STREQ(key, "visible")) {
            curr_tl->visible = *(u_char *) value;
        } else if (STREQ(key, "width")) {
            curr_tl->width = *(int *) value;
        } else if (STREQ(key, "x")) {
            curr_tl->x = *(int *) value;
        } else if (STREQ(key, "y")) {
            curr_tl->y = *(int *) value;
        }

        // Check if we should create a new list entry
        Tile_Layer *next;
        if(data->next != NULL) {
            next = malloc(sizeof(Tile_Layer));
        } else {
            next = NULL;
        }
        curr_tl->next = next;
    }
    tm->layers = root_tl;
}
