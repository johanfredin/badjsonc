#include <stdio.h>
#include <malloc.h>
#include "parser.h"
#define YOLO 2048

const char *daFile = "c:/users/lowrider/ClionProjects/playground/test.json";

FILE *getFile(const char *fileName) {
    FILE *file;
    fopen_s(&file, fileName, "r");
    if (file == NULL) {
        printf("File not found losah!");
        return NULL;
    }
    return file;
}

size_t calcBuffSize(size_t buffer_size, int inc_when_too_small) {
    FILE *file = getFile(daFile);

    char buffer_in[YOLO];
    int max = 0, lines = 1;
    char *currLine = fgets(buffer_in, 1024, file);
    while (currLine != NULL) {
        // Check length
        int i;
        for (i = 0; i < YOLO; i++) {
            if (buffer_in[i] == '\n') {
                if (i > max) {
                    max = i;
                }
                break;
            }

            // Check if we reached last index and still not at null terminator
            if (i == YOLO - 1) {
                printf("Buffer size=%d exceeded at line %d, incrementing....\n", buffer_size, lines);
                fclose(file);
                return calcBuffSize(buffer_size + inc_when_too_small, inc_when_too_small);
            }
        }
        lines++;
        currLine = fgets(buffer_in, buffer_size, file);
    }
    fclose(file);
    printf("Max buffer_in should be %d\n", max);
    return max;
}

char *getContent() {
    char *buffer = NULL;
    size_t length;
    FILE *file = getFile(daFile);
    fseek(file, 0, SEEK_END);
    length = ftell(file);
    fseek(file, 0, SEEK_SET);
    buffer = malloc(length);
    if (buffer) {
        fread(buffer, 1, length, file);
    }
    return buffer;
}

int main() {
    parser_init(getContent());
    JSON_Data* data = parser_parse();
    printf("hmm");
    return 0;
}
