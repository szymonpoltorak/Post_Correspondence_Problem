#include "memory.h"
#include <stdio.h>
#include <stdlib.h>

void freeAll(char** A, char** B, char* result_A, char* result_B, int n){
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

	if (tab != NULL) {
		for (int i = 0; i < n; i++) {
			tab[i] = (char*) malloc(100 * sizeof(char*));
			char u = 0;
			int j = 0;
			
			if (tab[i] != NULL) {
				while (true) {
					if (scanf("%c", &u) != 1){
						fprintf(stderr, "COULDN'T READ CHARACTER!\n");
						exit(EXIT_FAILURE);
					}

					if (u == '\n' || j >= 99) {
						break;
					}

					if (u == '0' || u == '1') {
						tab[i][j++] = u;
					} else {
						fprintf(stderr, "WRONG CHARACTER FOUND! PROCESS GONNA END!\n");
						exit(EXIT_FAILURE);
					}
				}
				tab[i][j] = '\0';
			}
		}

		return tab;
	}
	else {
		fprintf(stderr, "I CAN'T READ LIST !\n");
		exit(EXIT_FAILURE);
	}
}
