#include "prints.h"
#include <stdio.h>

void print_list(char** List, int n){
	for (int i = 0; i < n; i++) {
		printf("%s\t", List[i]);
	}
	printf("\n\n");
}

void print_result(int* solution, int size){
	printf("\nSOLUTION WAS FOUND! :\n");

	for (int i = 0; i < size; i++){
		printf("%d ", solution[i]);
	}
	printf("\n");	
}

void print_currents(char* result_A, int length_A, char* result_B, int length_B){
    printf("\nCurrent lists:\n");

	for (int i = 0; i < length_A; i++){
		printf("%c", result_A[i]);
	}
	
	printf("\t");

	for (int i = 0; i < length_B; i++){
		printf("%c", result_B[i]);
	}
	printf("\n\n");
}