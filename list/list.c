#include <stdlib.h>
#include <stdio.h>
#include "list.h"

void init(List * L) {
	L->head = NULL;
	L->tail = NULL;
}

void insert(List * L, int value) {
	Node * x;
	x = (Node *) malloc(sizeof(Node));
	x -> key = value;
	if(L->head == NULL) {
		x -> next = NULL;
		x -> prev = NULL;
		L -> tail = x;
		L -> head = x;
	} else {
		x -> next = L -> head;
		x -> prev = NULL;
		L -> head -> prev = x;
		L -> head = x;
	}
}

void write(List L) {
	Node * x = L.head;
	while(x != NULL) {
		printf("%d ", x -> key);
		x = x -> next;
	}
	putchar('\n');
}

void search(List L, int value) {
	int response = -1;
	Node * x = L.head;
	while(x != NULL) {
		if(x -> key == value){
			response = value;
		}
		x = x -> next;
	}
	printf("%d \n", response);
}


void insertAfter(List * L, int value, int afterValue) {
	Node * newNode;
	Node * x = L -> head;
	newNode = (Node *) malloc(sizeof(Node));
	newNode -> key = value;
	
	while(x != NULL) {
		if(x -> key == afterValue){
			if (x == L -> tail) {
				newNode -> next = NULL;
				newNode -> prev = x;
				x -> next = newNode;
				L -> tail = newNode;
			} else {
				newNode -> next = x -> next;
				newNode -> prev = x;
				x -> next -> prev = newNode;
				x -> next = newNode;
			}
			break;
		}
		x = x -> next;
	}
}

void insertBefore(List * L, int value, int beforeValue) {
	Node * newNode;
	Node * x = L -> head;
	newNode = (Node *) malloc(sizeof(Node));
	newNode -> key = value;
	
	while(x != NULL) {
		if(x -> key == beforeValue){
			if (x == L -> head) {
				newNode -> next = x;
				newNode -> prev = NULL;
				x -> prev = newNode;
				L -> head = newNode;
			} else {
				newNode -> prev = x -> prev -> next;
				newNode -> next = x;
				x -> prev -> next = newNode;
				x -> prev = newNode;
			}
			break;
		}
		x = x -> next;
	}
}

void deleteFromList(List * L, int value) {
	Node * x = L -> head;
	while(x != NULL) {
		if(x -> key == value){
			if(x == L -> head) {
				x -> next -> prev = NULL;
				L -> head = x -> next;
			}
			else if (x == L -> tail) {
				x -> prev -> next = NULL;
				L -> tail = x -> prev;
			}
			else {
				x -> next -> prev = x -> prev;
				x -> prev -> next = x -> next;
			}
			free(x);
			break;
		}
		x = x -> next;
	}
}

void clear(List * L) {
	Node * t;
	Node * x = L -> head;
	while(x != NULL) {
		t = x -> next;
		free(x);
		x = t;
	}
	L -> head = NULL;
}

