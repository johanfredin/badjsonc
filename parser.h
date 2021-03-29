//
// Created by lowrider on 2021-03-22.
//

#ifndef PSX_SPIKE_PARSER_H
#define PSX_SPIKE_PARSER_H

typedef unsigned char u_char;

typedef struct {
    u_char integer:1;
    u_char decimal:1;
    u_char str:1;
    u_char bool:1;
    u_char arr:1;
    u_char obj:1;
} Type;

typedef struct JSON_Data{
    char* key;
    void* value;
    Type type;
    struct JSON_Data* next;
} JSON_Data;

void parser_init(char* file_content);
JSON_Data* parser_parse();
JSON_Data* parser_parse2();

#endif //PSX_SPIKE_PARSER_H
