//
// Created by lowrider on 4/4/2021.
//

#ifndef BADJSON_UTILS_H
#define BADJSON_UTILS_H

#define STREQ(str1, str2) strcmp(str1, str2) == 0

#define STR_LEN(i, str) while ((char) str[i] != '\0') i++;

#define FREE_AND_NULL(ptr) if(ptr != NULL) free(ptr); ptr = NULL

#define MALLOC_IF_NEXT_NOT_NULL(ptr_to_check, curr_entry, ptr_type)     \
    if (ptr_to_check->next == NULL) {                                   \
        curr_entry->next = NULL;                                        \
    } else {                                                            \
        curr_entry->next = malloc(sizeof(ptr_type));                    \
        curr_entry = curr_entry->next;                                  \
    }

#endif //BADJSON_UTILS_H
