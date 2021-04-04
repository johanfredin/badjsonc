//
// Created by lowrider on 2021-03-30.
//

#include <malloc.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "filereader.h"

FILE *fr_get_file(const char *fileName) {
    char* absPath;
    char cwd[150];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Current working dir: %s\n", cwd);
    }

    absPath = strcat(cwd, fileName);
    FILE *file;
    file = fopen(absPath, "r");
    if (file == NULL) {
        printf("File='%s' not found!", absPath);
        exit(1);
    }
    return file;
}

char *fr_get_content(const char* fileName) {
    char *buffer = NULL;
    size_t length;
    FILE *file = fr_get_file(fileName);
    printf("File=%s retrieved\n", fileName);
    fseeko(file, 0, SEEK_END);
    length = ftello(file) + 1;   // Reserved for null terminator
    fseeko(file, 0, SEEK_SET);
    buffer = malloc(length);
    int i;
    for (i = 0; i < length; i++) {
        buffer[i] = 0;
    }
    if (buffer) {
        fread(buffer, 1, length, file);
        buffer[length - 1] = '\0';
    }

    return buffer;
}
