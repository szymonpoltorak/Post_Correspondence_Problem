#ifndef _POP_H_
#define _POP_H_

#include "memory.h"

#define REVERSED 2
#define CONTINUE 1
#define END 0

void find_solution(char** A, char** B, int n);

int choice(void);

void append(char* src, char* dest, int dest_size);

#endif