#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "tree.h"

void init(Tree * T) {
	T->root = NULL;
}

Node * randWalkTree(Tree * T) {
	Node * x;
	Node * y;
	x = T -> root;
	while(x != NULL) {
		y = x;
		if ((rand() % 2) == 0) {
			x = x -> left;
		} else {
			x = x -> right;
		}
	}
	return y;
}

void makeTree(Tree * T, int k) {
	int i;
	Node * x;
	Node * n;
	srand(time(0));
	for (i = 0; i < k; i++) {
		x = randWalkTree(T);
		n = (Node *) malloc(sizeof(Node));
		n -> parent = x;
		n -> left = NULL;
		n -> right = NULL;
		n -> key = (1 + rand() % 10);
		if(x -> left == NULL) {
			x -> left = n;
		} else {
			x -> right = n;
		}
		if(T -> root == NULL) {
			n -> parent = NULL;
			T -> root = n;
		}
	}
}

void walkTree(Node * N, int k) {
	int i;
	if(N != NULL) {
		walkTree(N -> left, k + 1);
		for(i = 0; i < k; i++) {
			printf("\t");
		}
		printf("%d \n", N -> key);
		walkTree(N -> right, k + 1);
	}
}

void printTree(Tree T) {
	walkTree(T.root, 0);
}

void walkPreorder(Node * N) {
	printf("%d  ", N -> key);
	if(N -> left != NULL) {	
		walkPreorder(N -> left);
	}
	if(N -> right != NULL) {
		walkPreorder(N -> right);
	}
}

void preorderTree(Tree T) {
	walkPreorder(T.root);
	printf("\n");
}

void walkInorder(Node * N) {
	if(N -> left != NULL) {	
		walkInorder(N -> left);
	}
	printf("%d  ", N -> key);
	if(N -> right != NULL) {
		walkInorder(N -> right);
	}
}

void inorderTree(Tree T) {
	walkInorder(T.root);
	printf("\n");
}

void walkPostorder(Node * N) {
	if(N -> left != NULL) {	
		walkPostorder(N -> left);
	}
	if(N -> right != NULL) {
		walkPostorder(N -> right);
	}
	printf("%d  ", N -> key);
}

void postorderTree(Tree T) {
	walkPostorder(T.root);
	printf("\n");
}

void clearNodes(Node * N) {
	if(N != NULL) {
		clearNodes(N -> left);
		clearNodes(N -> right);
		free(N);
	}
}

void clear(Tree * T) {
	clearNodes(T -> root);
	T -> root = NULL;
}

int leafCounter(Node * N) {
	if(N == NULL) {
		return 0;
	}
	if(N -> left == NULL && N -> right == NULL) {
		return 1;
	} else {
		return leafCounter(N -> left) + leafCounter(N -> right);
	}
}

int amountOfLeafs(Tree T) {
	return leafCounter(T.root);
}

