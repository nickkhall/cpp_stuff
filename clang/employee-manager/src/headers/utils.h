#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>

char** allocate_strs(const int* rows, const int* cols);
void write_to_strs(char **s, const int *rows, const int *cols);
void write_to_file(const char** labels, char **string, const int *size);

#endif

