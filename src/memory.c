#include "memory.h"
#include <stdio.h>
#include <stdlib.h>

void freeAll(char** A, char** B, char* result_A, char* result_B, int n, int* solution){
	if (solution != NULL){
		free(solution);
	}

	free(result_A);
	free(result_B);

	for(int i = 0; i < n; i++){
		free(A[i]);
		free(B[i]);
	}
	
	free(A);
	free(B);
}

char** read_list(int n) {
	char** tab = (char**) malloc (100 * sizeof(tab));

	if (tab == NULL){
		fprintf(stderr, "I CAN'T READ LIST !\n");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < n; i++) {
		tab[i] = (char*) malloc(100 * sizeof(char*));
		char u = 0;
		int j = 0;

		if (tab[i] == NULL){
			fprintf(stderr, "MALLOC FAILED!!\n");
			exit(EXIT_FAILURE);
		}
			
		while (true) {
			if (scanf("%c", &u) != 1){
				fprintf(stderr, "COULDN'T READ CHARACTER!\n");
				exit(EXIT_FAILURE);
			}

			if (u == '\n' || j >= 99) {
				break;
			}
			tab[i][j++] = u;
		}
		tab[i][j] = '\0';
	}

	return tab;
}
