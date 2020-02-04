#ifndef QUEUE_H
#define QUEUE_H

typedef
struct queue {
	int data[10];
	int length;
	int head;
	int tail;
}
Queue;

void initq(Queue *);

int queue_empty(Queue *);

void enqueue(Queue *, int);

int dequeue(Queue *);

void writeq(Queue *);

void writeq_empty(Queue *);

#endif
