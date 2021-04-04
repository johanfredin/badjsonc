//
// Created by lowrider on 2021-03-22.
//

#ifndef PSX_SPIKE_TILED_H
#define PSX_SPIKE_TILED_H

#include "parser.h"

typedef unsigned int u_int;
typedef unsigned char u_char;

typedef struct Object_Layer {
    u_int width, height;
    u_int id;
    char *name;
    char *type;
    u_char visible;
    u_int x, y;
    struct Object_Layer *next;
} Object_Layer;

typedef struct Tile_Layer {
    int *data;
    u_int height, width, id;
    char *name, *type;
    u_char visible;
    int x, y;
    struct Tile_Layer *next;
} Tile_Layer;

typedef struct Tile_Map {
    int width, height, tile_width, tile_height;
    Tile_Layer *layers;
    Object_Layer *objects;
} Tile_Map;

Tile_Map *tiled_populate_from_json(JSON_Data* root);

#endif //PSX_SPIKE_TILED_H
