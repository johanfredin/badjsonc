//
// Created by lowrider on 2021-03-22.
//

#ifndef PSX_SPIKE_PARSER_H
#define PSX_SPIKE_PARSER_H

typedef struct {
    int integer:1;
    int decimal:1;
    int str:1;
    int bool:1;
    int arr:1;
    int obj:1;
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
