//
// Created by lowrider on 2021-03-30.
//

#include <malloc.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "filereader.h"

FILE *get_file(const char *fileName) {
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

size_t calc_buff(const char *fileName, size_t buffer_size, int inc_when_too_small) {
    FILE *file = get_file(fileName);

    char buffer_in[BUFFER];
    int max = 0, lines = 1;
    char *currLine = fgets(buffer_in, 1024, file);
    while (currLine != NULL) {
        // Check length
        int i;
        for (i = 0; i < BUFFER; i++) {
            if (buffer_in[i] == '\n') {
                if (i > max) {
                    max = i;
                }
                break;
            }

            // Check if we reached last index and still not at null terminator
            if (i == BUFFER - 1) {
                printf("Buffer size=%li exceeded at line %d, incrementing....\n", buffer_size, lines);
                fclose(file);
                return calc_buff(fileName, buffer_size + inc_when_too_small, inc_when_too_small);
            }
        }
        lines++;
        currLine = fgets(buffer_in, buffer_size, file);
    }
    fclose(file);
    printf("Max buffer_in should be %d\n", max);
    return max;
}

char *get_content(const char* fileName) {
    char *buffer = NULL;
    size_t length;
    FILE *file = get_file(fileName);
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
