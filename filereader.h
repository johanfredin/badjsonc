//
// Created by lowrider on 2021-03-30.
//

#ifndef PSX_SPIKE_FILEREADER_H
#define PSX_SPIKE_FILEREADER_H

#include <stdio.h>

#define BUFFER 2048

FILE *get_file(const char *fileName);

size_t calc_buff(const char *fileName, size_t buffer_size, int inc_when_too_small);

char *get_content(const char *fileName);

#endif //PSX_SPIKE_FILEREADER_H
