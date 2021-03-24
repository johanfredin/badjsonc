//
// Created by lowrider on 2021-03-22.
//
#include <vcruntime.h>
#include <string.h>
#include <malloc.h>
#include <stdio.h>
#include "parser.h"
#include "tiled.h"

typedef unsigned int u_int;
typedef unsigned char u_char;

u_int idx = 0;
char *content = NULL;
JSON_Data *map;

u_int ff_to_start();

void *get_value();

char *get_str();

char skip_irrelevant_chars();

char curr_ch();

char next_ch();

void *get_array();

JSON_Data *get_object();

void *get_num();

u_char *get_bool();

u_char is_num();

void parser_init(char *file_content) {
    content = file_content;
}

JSON_Data *parser_parse() {
    idx = ff_to_start();
    u_int count = 0;
    JSON_Data* data = calloc(500, sizeof(JSON_Data));
    while (content[idx] != '\0') {
        JSON_Data entry = data[count];
        skip_irrelevant_chars();
        if (idx == strlen(content) - 1 && curr_ch() == '}') {
            break;
        }
        entry.key = get_str();
        entry.value = get_value();
        printf("Key=%s, value=%s\n", entry.key, (char*) entry.value);
        count++;
        idx++;
    }
    return data;
}

void *get_value() {
    char c = curr_ch();
    void *value;
    if (c == '\"') {
        idx++;
        value = get_str();
    } else if (c == '[') {
        idx++;
        skip_irrelevant_chars();
        value = get_array();
    } else if (c == '{') {
        idx++;
        skip_irrelevant_chars();
        value = get_object();
    } else if (is_num()) {
        value = get_num();
    } else if (c == 't' || c == 'f') {
        value = get_bool();
    } else {
        idx++;
        skip_irrelevant_chars();
        value = get_value();
    }
    return value;
}

u_char is_num() {
    char c = curr_ch();
    int i;
    char numbers[] = "0123456789.\0";
    for (i = 0; numbers[i] != '\0'; i++) {
        if (numbers[i] == c) {
            return 1;
        }
    }
    return 0;
}

u_char *get_bool() {
    u_char* bool_ptr = malloc(sizeof(u_char));
    *bool_ptr = 0;
    if(curr_ch() == 't') {
        *bool_ptr = 1;
    }
    return bool_ptr;
}

void *get_num() {
    int i = 0, is_int = 1;
    void* num_ptr = malloc(sizeof(float));
    char value[15];
    while (is_num()) {
        value[i] = curr_ch();
        next_ch();
        i++;
    }
    value[i] = '\0';

    for (i = 0; i < 15 && value[i] != '\0'; i++) {
        if(value[i] == '.') {
            num_ptr = (float*) value;
            is_int = 0;
        }
    }

    if (is_int) {
        num_ptr = (int*) value;
    }

    return num_ptr;
}

JSON_Data *get_object() {
    JSON_Data* data = calloc(50, sizeof(JSON_Data));
    int count = 0;
    char* key;
    void* value;
    char c = curr_ch();
    while (c != '}') {
        JSON_Data entry = data[count];
        skip_irrelevant_chars();
        key = get_str();
        skip_irrelevant_chars();
        value = get_value();
        entry.key = key;
        entry.value = value;
        c = skip_irrelevant_chars();
        count++;
    }
    next_ch(); // So that we iterate past the last } char
    return data;
}

void *get_array() {
    int i = 0;
    char c = curr_ch();
    void** array = calloc(100, sizeof(int));
    while (c != ']') {
        skip_irrelevant_chars();
        array[i] = get_value();
        c = skip_irrelevant_chars();
    }
    next_ch(); // So that we iterate past the last ] char
    return array;
}

char *get_str() {
    char* key = calloc(32, sizeof(char));
    int i = 0;
    char c = curr_ch();
    if (c == '\"') {
        c = next_ch();
    }

    while (c != '\"') {
        key[i] = c;
        c = next_ch();
        i++;
    }
    key[i] = '\0';
    next_ch(); // So that we iterate past the last " char
    return key;
}

u_int ff_to_start() {
    while (content[idx] != '\0') {
        if (content[idx++] == '{') {
            return idx;
        }
    }
    return 0;
}

char skip_irrelevant_chars() {
    char c = curr_ch();
    while (c == ' ' || c == '\r' || c == '\n' || c == '\t' || c == ',') {
        c = next_ch();
    }
    return c;
}

char curr_ch() {
    return content[idx];
}

char next_ch() {
    return content[++idx];
}