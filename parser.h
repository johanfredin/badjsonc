//
// Created by lowrider on 2021-03-22.
//

#ifndef PSX_SPIKE_PARSER_H
#define PSX_SPIKE_PARSER_H

typedef struct JSON_Data {
    char* key;
    void* value;
    struct JSON_Data* next;
} JSON_Data;

void parser_init(char* file_content);
JSON_Data* parser_parse();

#endif //PSX_SPIKE_PARSER_H
