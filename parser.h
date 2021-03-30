//
// Created by lowrider on 2021-03-22.
//

#ifndef PSX_SPIKE_PARSER_H
#define PSX_SPIKE_PARSER_H

typedef struct {
    unsigned char integer:1;
    unsigned char decimal:1;
    unsigned char str:1;
    unsigned char bool:1;
    unsigned char arr:1;
    unsigned char obj:1;
} Type;

typedef struct JSON_Data{
    char* key;
    void* value;
    Type type;
    struct JSON_Data* next;
    struct JSON_Data* child;
} JSON_Data;

JSON_Data* parser_parse(char* file_content);
void parser_print(JSON_Data* data);

#endif //PSX_SPIKE_PARSER_H
