#include <stdlib.h>
#include <stdio.h>
#include "bst.h"

void init(Tree * T) {
	T -> root = NULL;
}

void setParentForNewNode(Node * x, Node * n) {
	if ((n -> key < x -> key) && (x -> left == NULL)) {
		x -> left = n;
		n -> parent = x;
	} else if (n -> key < x -> key) {
		setParentForNewNode(x -> left, n);
	} 
	if ((n -> key >= x -> key) && (x -> right == NULL)) {
		x -> right = n;
		n -> parent = x;
	} else if (n -> key >= x -> key)  {
		setParentForNewNode(x -> right, n);
	}
}

void insert(Tree * T, int v) {
	Node * n = (Node *) malloc(sizeof(Node));
	n -> left = NULL;
	n -> right = NULL;
	n -> key = v;
	if (T -> root == NULL) {
		n -> parent = NULL;
		T -> root = n;
	} else {
		setParentForNewNode(T -> root, n);
	}
}

void walkTree(Node * N, int k) {
	int i;
	if(N != NULL) {
		walkTree(N -> right, k + 1);
		for(i = 0; i < k; i++) {
			printf("\t");
		}
		printf("%d \n", N -> key);
		walkTree(N -> left, k + 1);
	}
}

void printTree(Tree T) {
	walkTree(T.root, 0);
}

int recursiveNodeSearch(Node * N, int k) {
	if (N -> key == k) {
		return N -> key;
	}
	if (N -> key <= k) {
		return recursiveNodeSearch(N -> right, k);
	}
	if (N -> key > k) {
		return recursiveNodeSearch(N -> left, k);
	}
	return 0;
}

int recursiveSearch(Tree T, int k) {
	return recursiveNodeSearch(T.root, k);
}

int iterativeNodeSearch(Node * N, int k) {
	while (N -> left != NULL && N -> right != NULL) {
		if (N -> left -> key == k) {
			return N -> left -> key;
		}
		if (N -> right -> key == k) {
			return N -> right -> key;
		}
		if (N -> key <= k) {
			N = N -> right;
		}
		if (N -> key > k) {
			N = N -> left;
		}
	}
	return 0;
}

int iterativeSearch(Tree T, int k) {
	return iterativeNodeSearch(T.root, k);
}

int findSuccessor(Node * N) {
	int k;
	if (N -> left == NULL) {
		k = N -> key;
		N = N -> parent;
		while (N -> key < k) {
			N = N -> parent;
		}
		return N -> key;
	} else {
		N = N -> right;
		if (N -> left == NULL) {
			return N -> key;
		}
		while (N -> left != NULL) {
			N = N -> left;
		}
		return N -> key;
	}
}

int successorOnNodes(Node * N, int k) {
	while (N -> left != NULL && N -> right != NULL) {
		if (N -> left -> key == k) {
			return findSuccessor(N -> left);
		}
		if (N -> right -> key == k) {
			return findSuccessor(N -> right);
		}
		if (N -> key <= k) {
			N = N -> right;
		}
		if (N -> key > k) {
			N = N -> left;
		}
	}
	return 0;
}

int successor(Tree T, int k) {
	return successorOnNodes(T.root, k);
}

void findNodeAndDelete(Node * N, int k, Tree T);

void deleteNodeWithoutKids(Node * N) {
	if (N -> parent -> key < N -> key) {
			N -> parent -> right = NULL;
		} else {
			N -> parent -> left = NULL;
		}
		free(N);
}

void deleteNodeWithOneKid(Node * N) {
	if (N -> left == NULL) {
			if (N -> parent -> key < N -> key) {
				N -> parent -> right = N -> right;
			} else {
				N -> parent -> left = N -> right;
		}
		} else {
			if (N -> parent -> key < N -> key) {
				N -> parent -> right = N -> left;
			} else {
				N -> parent -> left = N -> left;
		}
		}
		free(N);
}

void deleteNodeWithTwoKid(Node * N, Tree T) {
	int succeessorKeyValue = successor(T, recursiveSearch(T, N -> key));
	findNodeAndDelete(T.root, succeessorKeyValue, T);
	N -> key = succeessorKeyValue;
}

void deleteNodeWithValue(Node * N, Tree T) {
	if ((N -> left == NULL) && (N -> right == NULL)) {
		deleteNodeWithoutKids(N);
	}
	if (((N -> left == NULL) && (N -> right != NULL)) || ((N -> left != NULL) && (N -> right == NULL))) {
		deleteNodeWithOneKid(N);
	}
	if ((N -> left != NULL) && (N -> right != NULL)) {
		deleteNodeWithTwoKid(N, T);
	}
}

void findNodeAndDelete(Node * N, int k, Tree T) {
	while (N -> left != NULL || N -> right != NULL) {
		if (N -> left != NULL && N -> left -> key == k) {
			deleteNodeWithValue(N -> left, T);
			break;
		}
		if (N -> right != NULL && N -> right -> key == k) {
			deleteNodeWithValue(N -> right, T);
			break;
		}
		if (N -> key <= k) {
			N = N -> right;
		}else if (N -> key > k) {
			N = N -> left;
		}
	}
}

void deleteFromTree(Tree * T, int k, Tree W) {
	findNodeAndDelete(T -> root, k, W);
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


int successorOfSmallest(Tree T) {
	Node * x = T.root;
	while (x -> left != NULL) {
		x = x -> left;
	}
	return successor(T, x -> key);
}
