#include "stack.h"
#include "queueB.h"
#include <stdio.h>

void initqb(QueueB * Q) {
	init(&(Q->s1));
	init(&(Q->s2));
	Q->length = 10;
	Q->head = 0;
	Q->tail = 0;
}

int queueb_empty(QueueB * Q) {
	if(Q->head == Q->tail) {
		return 1;
	}
	return 0;
}

void enqueueb(QueueB * Q, int k) {
	push(&(Q->s1), k);
	Q->tail++;
}

int dequeueb(QueueB * Q) {
	int response;
	int i;
	if(Q->tail == Q->head) {
		printf("niedomiar \n");
		return 0;
	}
	else {
		for(i = 0; i < (Q->tail) - 1; i++) {
			push((&(Q->s2)), pop(&(Q->s1)));
		}
		
		response = pop(&(Q->s1));
		Q->tail--;
		
		for(i = 0; i < (Q->tail); i++) {
			push((&(Q->s1)), pop(&(Q->s2)));
		}
		return response;
	}
}

void writeqb(QueueB * Q) {
	write(&(Q->s1));
}

void writeqb_empty(QueueB * Q) {
	if (queueb_empty(Q) == 1) {
		printf("true \n");
	}
	else {
		printf("false \n");
	}
}
