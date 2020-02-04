#include <stdio.h>
#include "bst.h"

int main(int argc, char *argv[]) {
	
	Tree T;
	
	init(&T);
	insert(&T, 15);
	insert(&T, 5);
	insert(&T, 16);
	insert(&T, 3);
	insert(&T, 12);
	insert(&T, 20);
	insert(&T, 10);
	insert(&T, 6);
	insert(&T, 7);
	insert(&T, 13);
	insert(&T, 18);
	insert(&T, 23);
	printTree(T);
	printf("\n===============================\n");
	
	printf("%d\n", recursiveSearch(T, 13));
	printf("%d\n", iterativeSearch(T, 13));
	printf("%d\n", successor(T, recursiveSearch(T, 5)));
	printf("%d\n", successor(T, recursiveSearch(T, 13)));
	printf("===============================\n");
	deleteFromTree(&T, 13, T);
	printTree(T);
	printf("\n===============================\n");
	deleteFromTree(&T, 16, T);
	printTree(T);
	printf("\n===============================\n");
	deleteFromTree(&T, 5, T);
	printTree(T);
	clear(&T);
	printTree(T);
	printf("\n===============================\n");
	init(&T);
	insert(&T, 15);
	insert(&T, 5);
	insert(&T, 16);
	insert(&T, 3);
	insert(&T, 12);
	insert(&T, 20);
	insert(&T, 10);
	insert(&T, 6);
	insert(&T, 7);
	insert(&T, 13);
	insert(&T, 18);
	insert(&T, 23);
	printf("Nastepnik najmniejszego (pierwotne drzewo): %d", successorOfSmallest(T));
	clear(&T);
	printTree(T);
	printf("\n===============================\n");
	
	return 0;
}
