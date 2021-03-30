//
// Created by lowrider on 2021-03-28.
//
#include <vcruntime.h>
#include <malloc.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "parser.h"

unsigned int idx = 0;
char *content = NULL;

void ff_to_start();
void get_value(JSON_Data *);
char *get_str();
char skip_irrelevant_chars();
char curr_ch();
char next_ch();
void get_array(JSON_Data*);
JSON_Data *get_object();
void get_bool(JSON_Data*);
unsigned char is_num();

void get_number(JSON_Data *entry);

void parser_init(char *file_content) {
    content = file_content;
}

JSON_Data* malloc_json_entry() {
    Type zeroType = {0, 0, 0, 0, 0, 0};
    JSON_Data *data = malloc(sizeof(JSON_Data));
    data->next = NULL;
    data->child = NULL;
    data->type = zeroType;
    return data;
}

JSON_Data *parser_parse2() {
    JSON_Data *root, *curr;
    root = malloc_json_entry();
    curr = root;
    ff_to_start();
    while (content[idx] != '\0') {
        skip_irrelevant_chars();

        curr->key = get_str();
        skip_irrelevant_chars();
        get_value(curr);

        // Go to next if we have not reached the end yet
        unsigned int nextIdx = idx + 1;
        char nextChar = content[nextIdx];
        if (nextChar == '\0' || (nextChar == '}' && content[++nextIdx] == '\0')) {
            break;
        }
        curr->next = malloc_json_entry();
        curr = curr->next;
        idx++;
    }
    return root;
}

char* read_until(char end_char, unsigned char include_end_char) {
    char *str = calloc(32, sizeof(char));
    int i = 0;
    char c = curr_ch();
    while (c != end_char) {
        str[i] = c;
        c = next_ch();
        i++;
    }
    if(include_end_char) {
        str[i] = end_char;
        i++;
    }
    str[i] = '\0';
    next_ch(); // So that we iterate past the last " char
    return str;
}

char *get_str() {
    if (curr_ch() == '\"') {
        next_ch();
    }
    return read_until('\"', 0);
}

char *get_numeric_str() {
    int i = 0;
    char *str = calloc(15, sizeof(char));
    while (is_num()) {
        str[i] = curr_ch();
        next_ch();
        i++;
    }
    str[i] = '\0';
    return str;
}

void get_value(JSON_Data *entry) {
    char c = curr_ch();
    if (c == '\"') {
        idx++;
        entry->value = get_str();
        entry->type.str = 1;
    }
    else if (c == '[') {
        idx++;
        skip_irrelevant_chars();
        get_array(entry);
//    } else if (c == '{') {
//        idx++;
//        skip_irrelevant_chars();
//        value = get_object();
//        type.obj = 1;
    } else if (is_num()) {
        get_number(entry);
    } else if (c == 't' || c == 'f') {
        get_bool(entry);
    } else {
        idx++;
        skip_irrelevant_chars();
        get_value(entry);
    }
}

void get_number(JSON_Data *entry) {
    char *num_str = get_numeric_str();
    float* f_ptr;
    int* i_ptr;
    if(strchr(num_str, '.')) {
        f_ptr = malloc(sizeof(float));
        *f_ptr = strtof(num_str, NULL);
        entry->value = f_ptr;
        entry->type.decimal = 1;
    } else {
        i_ptr = malloc(sizeof(int));
        *i_ptr = strtol(num_str, NULL, 10);
        entry->value = i_ptr;
        entry->type.integer = 1;
    }
    free(num_str);
}

void get_bool(JSON_Data* entry) {
    char* str_bool = read_until('e', 1);   // true and false both end at 'e'
    unsigned char *bool_ptr = malloc(sizeof(unsigned char));
    if(strcmp(str_bool, "true") == 0) {
        *bool_ptr = 1;
    } else {
        *bool_ptr = 0;
    }
    free(str_bool);
    str_bool = NULL;
    entry->value = bool_ptr;
    entry->type.bool = 1;
}

void get_array(JSON_Data* entry) {
    char c = curr_ch();
    JSON_Data* arr_root = malloc_json_entry();
    JSON_Data* arr_curr = arr_root;
    entry->type.arr = 1;
    while (c != ']') {
        JSON_Data* next = NULL;
        skip_irrelevant_chars();
        get_value(arr_curr);
        c = skip_irrelevant_chars();

        if(c == ']') {
            break;
        }
        next = malloc_json_entry();
        arr_curr->next = next;
        arr_curr = arr_curr->next;
    }

    entry->child = arr_root;
    next_ch(); // So that we iterate past the last ] char
}

unsigned char is_num() {
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

void ff_to_start() {
    while (content[idx] != '\0') {
        if (content[idx++] == '{') {
            return;
        }
    }
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
    if(curr_ch() == '\0') {
        return curr_ch();
    }
    return content[++idx];
}