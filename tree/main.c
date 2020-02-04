#include "tree.h"
#include <stdio.h>

int main() {
	Tree T;
	int leafsCounter;
	
	printf("Standard: \n\n"); 
	init(&T);
	makeTree(&T, 10);
	printTree(T);
	preorderTree(T);
	inorderTree(T);
	postorderTree(T);
	clear(&T);
	printTree(T);
	
	printf("\n\n============================ \n"); 
	printf("LeafCounter: \n\n"); 
	
	init(&T);
	makeTree(&T, 10);
	printTree(T);
	leafsCounter = amountOfLeafs(T);
	printf("\n\nAmount of leafs: %d\n\n", leafsCounter);
	clear(&T);
	printTree(T);
	
	return 0;
}
