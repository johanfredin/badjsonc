#include "parser.h"
#include "filereader.h"

const char *fileName = "..\\res\\0_0.json";

int main() {
    char *content = get_content(fileName);
    JSON_Data *data = parser_parse(content);
    parser_print(data);
    return 0;
}
