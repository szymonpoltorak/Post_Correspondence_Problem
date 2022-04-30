#include <stdio.h>
#include <stdlib.h>
#include "pop.h"
#include "memory.h"
#include "prints.h"

int main(void) {
	int n = 0, temp = 0;

	printf("Please give number of chains: ");
	if (scanf("%d", &n) != 1){
		fprintf(stderr, "COULDN'T READ NUMBER!!!\n");
		exit(EXIT_FAILURE);
	}
	
	temp = getchar();

	printf("Please give elements of list A:\n");
	char** A = read_list(n);

	printf("Please give elements of list B:\n");
	char** B = read_list(n);

	printf("List A: \n");
	print_list(A, n);

	printf("List B: \n");
	print_list(B, n);

	printf("Please remember that indexes start from 0\n\n");
	find_solution(A, B, n);

	exit(EXIT_SUCCESS);
}