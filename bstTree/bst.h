#ifndef BST_H
#define BST_H

struct node;
struct tree;

typedef
struct node {
	int key;
	struct node * parent;
	struct node * left;
	struct node * right;
} Node;

typedef
struct tree {
	Node * root;
} Tree;

void init(Tree *);

void insert(Tree *, int);

void printTree(Tree);

int recursiveSearch(Tree, int);

int iterativeSearch(Tree, int);

int successor(Tree, int);

void deleteFromTree(Tree *, int, Tree);

void clear(Tree * T);

int successorOfSmallest(Tree);

#endif
