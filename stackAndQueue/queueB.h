#ifndef QUEUEB_H
#define QUEUEB_H

typedef
struct queueb {
	Stack s1;
	Stack s2;
	int length;
	int head;
	int tail;
}
QueueB;

void initqb(QueueB *);

int queueb_empty(QueueB *);

void enqueueb(QueueB *, int);

int dequeueb(QueueB *);

void writeqb(QueueB *);

void writeqb_empty(QueueB *);

#endif
