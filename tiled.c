//
// Created by lowrider on 2021-03-22.
//

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tiled.h"

void add_tile_layers_to_map(Tile_Map *tm, JSON_Data *jobj_root);
void add_data_to_layer(Tile_Layer *layer, JSON_Data *root);
void add_object_layers_to_map(Tile_Map *tm, JSON_Data *root, Object_Layer_Type type);

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
            // Linked list of json bounds found
            add_tile_layers_to_map(tm, (JSON_Data *) value);
        }
    }
    return tm;
}

void tiled_free(Tile_Map *tm) {
    Tile_Layer *tile_layer;
    tile_layer = tm->layers;
    while (tile_layer != NULL) {
        Tile_Layer *aux;
        aux = tile_layer;
        tile_layer = tile_layer->next;
        FREE_LINKED_LIST(aux->data, Layer_Data);
        FREE_AND_NULL(aux);
    }
    FREE_LINKED_LIST(tm->bounds, Object_Layer);
    FREE_LINKED_LIST(tm->teleports, Object_Layer);
    FREE_AND_NULL(tm);
}

void add_tile_layers_to_map(Tile_Map *tm, JSON_Data *jobj_root) {
    Tile_Layer *tl_root = malloc(sizeof(Tile_Layer));
    JSON_Data *jobj_curr;
    Tile_Layer *tl_curr, *tl_prev;

    for (jobj_curr = jobj_root, tl_curr = tl_root; jobj_curr != NULL; jobj_curr = jobj_curr->next) {
        JSON_Data *curr_layer;
        for (curr_layer = (JSON_Data *) jobj_curr->value; curr_layer != NULL; curr_layer = curr_layer->next) {
            char *key = curr_layer->key;
            void *value = curr_layer->value;

            if (STREQ(key, "data")) {
                add_data_to_layer(tl_curr, (JSON_Data *) value);
            } else if (STREQ(key, "height")) {
                tl_curr->height = *(int *) value;
            } else if (STREQ(key, "id")) {
                tl_curr->id = *(int *) value;
            } else if (STREQ(key, "name")) {
                u_char is_bounds = STREQ((char *) value, "bounds");
                u_char is_teleports = STREQ((char *) value, "teleports");
                if (is_bounds || is_teleports) {
                    // FF until we reach objects array
                    while (!(STREQ(curr_layer->key, "objects"))) {
                        curr_layer = curr_layer->next;
                    }
                    // Value should now be at objects root
                    value = curr_layer->value;  // Sync
                    add_object_layers_to_map(
                            tm,
                            (JSON_Data *) value,
                            is_bounds ? BOUNDS : TELEPORTS
                    );
                    FREE_AND_NULL(tl_curr);
                    tl_curr = tl_prev;

                } else {
                    tl_curr->name = (char *) value;
                }
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
        Tile_Layer *next = NULL;
        if (jobj_curr->next != NULL) {
            next = malloc(sizeof(Tile_Layer));
        }
        tl_curr->next = next;
        tl_prev = tl_curr;
        tl_curr = next;

    }
    tm->layers = tl_root;
}

void add_object_layers_to_map(Tile_Map *tm, JSON_Data *root, Object_Layer_Type type) {
    Object_Layer *ol_root, *ol_curr; // Our object layers linked list
    JSON_Data *curr_obj_layer; // Our current json object being iterated
    ol_root = malloc(sizeof(Object_Layer));
    ol_curr = ol_root;
    for (curr_obj_layer = root; curr_obj_layer != NULL; curr_obj_layer = curr_obj_layer->next) {    // Iterate objects
        JSON_Data *entry_root = (JSON_Data *) curr_obj_layer->value;
        JSON_Data *entry_curr;
        for (entry_curr = entry_root; entry_curr != NULL; entry_curr = entry_curr->next) { // Iterate object properties
            char *key = entry_curr->key;
            void *value = entry_curr->value;

            if (STREQ(key, "height")) {
                ol_curr->height = *(u_int *) value;
            } else if (STREQ(key, "id")) {
                ol_curr->id = *(u_int *) value;
            } else if (STREQ(key, "visible")) {
                ol_curr->visible = *(u_char *) value;
            } else if (STREQ(key, "width")) {
                ol_curr->width = *(u_int *) value;
            } else if (STREQ(key, "x")) {
                ol_curr->x = *(u_int *) value;
            } else if (STREQ(key, "y")) {
                ol_curr->y = *(u_int *) value;
            }
        }
        MALLOC_AND_MOVE_TO_NEXT_IF_MORE_DATA(curr_obj_layer, ol_curr, Object_Layer);
    }

    if (type == BOUNDS) {
        tm->bounds = ol_root;
    } else {
        tm->teleports = ol_root;
    }
}

void add_data_to_layer(Tile_Layer *layer, JSON_Data *root) {
    int data_count = 0;
    Layer_Data *data_root = malloc(sizeof(Layer_Data));
    Layer_Data *data = data_root;
    JSON_Data *curr;
    for (curr = root; curr != NULL; curr = curr->next) {
        data->id = *(u_short *) curr->value;
        MALLOC_AND_MOVE_TO_NEXT_IF_MORE_DATA(curr, data, Layer_Data)
        data_count++;
    }
    layer->data = data_root;
    layer->data_count = data_count;
}
