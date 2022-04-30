#ifndef _MEMORY_H_
#define _MEMORY_H_

#include <stdbool.h>

void freeAll(char** A, char** B, char* result_A, char* result_B, int n);

char** read_list(int n);

#endif