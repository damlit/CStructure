#ifndef LIST_H
#define LIST_H

struct node;

typedef
struct node {
	int key;
	struct node * next;
	struct node * prev;
} Node;

typedef
struct list {
	Node * head;
	Node * tail;
} List;

void init(List *);

void insert(List *, int);

void write(List);

void search(List, int);

void insertAfter(List *, int, int);

void insertBefore(List *, int, int);

void deleteFromList(List *, int);

void clear(List *);

#endif	
