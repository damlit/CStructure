#include "queue.h"
#include <stdio.h>

void initq(Queue * Q) {
	Q->length = 10;
	Q->head = 0;
	Q->tail = 0;
}

int queue_empty(Queue * Q) {
	if(Q->head == Q->tail) {
		return 1;
	}
	return 0;
}

void enqueue(Queue * Q, int k) {
	Q->data[Q->tail] = k;
	Q->tail++;
}

int dequeue(Queue * Q) {
	int response;
	int i;
	if(Q->tail == Q->head) {
		printf("niedomiar \n");
		return 0;
	}
	else {
		response = Q->data[Q->head];
		for(i = 0; i < (Q->tail); i++) {
			Q->data[i] = Q->data[i + 1];
		}
		Q->tail--;
		return response;
	}
}

void writeq(Queue * Q) {
	if(Q->tail != 0) {
		int i;
		for(i = 0; i < Q->tail; i++) {
			printf("%d ", Q->data[i]);
		}
	}
	printf("\n");
}

void writeq_empty(Queue * Q) {
	if (queue_empty(Q) == 1) {
		printf("true \n");
	}
	else {
		printf("false \n");
	}
}
