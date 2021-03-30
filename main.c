#include "parser.h"
#include "filereader.h"

const char *rel = "..\\res\\test_medium.json";

int main() {
    char *content = get_content(rel);
    JSON_Data *data = parser_parse(content);
    return 0;
}
