#include <malloc.h>
#include "parser.h"
#include "filereader.h"

const char *fileName = "/res/test_medium.json";

int main() {
    char *content = get_content(fileName);
    JSON_Data *data = parser_parse(content);
    parser_print(data);
    parser_free(data);
    return 0;
}
