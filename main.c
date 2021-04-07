#include "parser.h"
#include "filereader.h"
#include "tiled.h"


const char *fileName = "/res/0_0.json";

int main() {
    char *content = fr_get_content(fileName);
    JSON_Data *data = parser_parse(content);
    parser_print(data);
    Tile_Map *map = tiled_populate_from_json(data);
    tiled_free(map);
    parser_free(data);
    return 0;
}
