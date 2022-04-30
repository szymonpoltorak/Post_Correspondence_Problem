#include "pop.h"
#include "prints.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void find_solution(char** A, char** B, int n) {
	char* result_A = (char*) malloc(100 * sizeof(*result_A));
	char* result_B = (char*) malloc(100 * sizeof(*result_B));
	int* solution = (int*) malloc (100 * sizeof(*solution));
	int size = 0, length_A = 0, length_B = 0;

	if (result_A == NULL || result_B == NULL || solution == NULL) {
		fprintf(stderr, "LIST IS NULL !!!!\n");
		exit(EXIT_FAILURE);
	}

	result_A[0] = 0;
	result_B[0] = 0;

	while (true) {
		int index = 0;
		int temp = -1;

		printf("Please give me index: ");
		if (scanf("%d", &index) != 1){
			fprintf(stderr, "COULDN'T READ GIVEN INDEX!\n");

			if (choice() == false){
				freeAll(A, B, result_A, result_B, n, solution);
				exit(EXIT_SUCCESS);
			}
			continue;
		}

		if (index > n - 1) {
			printf("WRONG INDEX GIVEN !!!!\n");

			if (choice() == false){
				freeAll(A, B, result_A, result_B, n, solution);
				exit(EXIT_SUCCESS);
			}
			continue;
		}

		append(A[index], result_A, length_A);
		append(B[index], result_B, length_B);
		solution[size++] = index;

		length_A = strlen(result_A);
		length_B = strlen(result_B);

		print_currents(result_A, length_A, result_B, length_B);

		if (strcmp(result_A, result_B) == 0) {
			print_result(solution, size);
			freeAll(A, B, result_A, result_B, n, solution);
			exit(EXIT_SUCCESS);
		}
		
		if ((temp = choice()) == END){
			freeAll(A, B, result_A, result_B, n, solution);
			exit(EXIT_SUCCESS);
		} 
		else if (temp == REVERSED){
			solution[size--] = -1;
			length_A = strlen(result_A) - strlen(A[index]);
			length_B = strlen(result_B) - strlen(B[index]);
			print_currents(result_A, length_A, result_B, length_B);
		}
	}
	freeAll(A, B, result_A, result_B, n, solution);
}

void append(char* src, char* dest, int dest_size) {
    int src_size = strlen(src);

    for (int i = 0; i <= src_size; i++) {
        dest[dest_size + i] = src[i];
    }
}

int choice(void) {
	char k = 0;

	printf("Do you want to continue ? Write yes - 'y' or no - 'n' or 'r' to reverse last index\n");

	while (true) {
		if (scanf(" %c", &k) != 1){
			fprintf(stderr, "COULDN'T READ CHOICE!!\n");
		}

		if (k == 'n') {
			printf("\nSOLUTION WAS NOT FOUND!\n");
			return END;
		} else if (k == 'y') {
			break;
		} else if (k == 'r') {
			return REVERSED;
		} else {
			fprintf(stderr, "WRONG CHOICE FOUND !!!\n");
		}
	}

	return CONTINUE;
}
