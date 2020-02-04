#ifndef TREE_H
#define TREE_H

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

void makeTree(Tree *, int);

void printTree(Tree);

void preorderTree(Tree);

void inorderTree(Tree);

void postorderTree(Tree);

void clear(Tree * T);

int amountOfLeafs(Tree T);

#endif
