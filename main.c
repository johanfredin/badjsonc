#include <stdio.h>

#define YOLO 2048

typedef unsigned int u_int;
typedef unsigned char u_char;

typedef struct Object_Layer {
    u_int width, height;
    u_int id;
    char* name;
    char* type;
    u_char visible;
    u_int x, y;
} Object_Layer;

typedef struct Tile_Layer {
    int *data;
    u_int height;
    u_int id;
    char *name;
    char *type;
    u_char visible;
    int x;
    int y;
    Object_Layer *objects;
} Tile_Layer;

typedef struct Tile_Map {
    int width, height, tile_width, tile_height;
    Tile_Layer *layers;
} Tile_Map;

size_t curr_buffer_size = YOLO;
const char *daFile = "c:/users/lowrider/ClionProjects/playground/0_0.json";

size_t calcBuffSize(size_t buffer_size, int inc_when_too_small) {
    FILE *file;
    fopen_s(&file, daFile, "r");
    if (file == NULL) {
        printf("File not found losah!");
        return -1;
    }

    char buffer_in[YOLO];
    int max = 0, lines = 1;
    char *currLine = fgets(buffer_in, 1024, file);
    while (currLine != NULL) {
        // Check length
        int i;
        for (i = 0; i < YOLO; i++) {
            if (buffer_in[i] == '\n') {
                if (i > max) {
                    max = i;
                }
                break;
            }

            // Check if we reached last index and still not at null terminator
            if (i == YOLO - 1) {
                printf("Buffer size=%d exceeded at line %d, incrementing....\n", buffer_size, lines);
                fclose(file);
                return calcBuffSize(buffer_size + inc_when_too_small, inc_when_too_small);
            }
        }
        lines++;
        currLine = fgets(buffer_in, buffer_size, file);
    }
    fclose(file);
    printf("Max buffer_in should be %d\n", max);
    return max;
}


void parseMF() {

}

int main() {
    curr_buffer_size = calcBuffSize(1000, 200);
    parseMF();
    return 0;
}
