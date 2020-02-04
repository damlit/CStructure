#include "stack.h"
#include "queue.h"
#include "queueB.h"
#include <stdio.h>

int main() {
	
	Stack stk;
	Queue q;
	QueueB qb;
	
	printf("  STACK: \n");
	
	init(&stk);
	push(&stk, 1);
	push(&stk, 2);
	write(&stk);
	push(&stk, 3);
	write(&stk);
	write_empty(&stk);
	write_int(pop(&stk));
	write_int(pop(&stk));
	write(&stk);
	write_int(pop(&stk));
	write_int(pop(&stk));
	write(&stk);
	write_empty(&stk);
	
	
	printf("\n\n  QUEUE: \n");
	
	initq(&q);
	enqueue(&q, 1);
	enqueue(&q, 2);
	writeq(&q);
	enqueue(&q, 3);
	writeq(&q);
	writeq_empty(&q);
	write_int(dequeue(&q));
	write_int(dequeue(&q));
	writeq(&q);
	write_int(dequeue(&q));
	write_int(dequeue(&q));
	writeq(&q);
	writeq_empty(&q);
	
	
	printf("\n\n  QUEUE with two stacks: \n");
	
	initqb(&qb);
	enqueueb(&qb, 1);
	enqueueb(&qb, 2);
	writeqb(&qb);
	enqueueb(&qb, 3);
	writeqb(&qb);
	writeqb_empty(&qb);
	write_int(dequeueb(&qb));
	write_int(dequeueb(&qb));
	writeqb(&qb);
	write_int(dequeueb(&qb));
	write_int(dequeueb(&qb));
	writeqb(&qb);
	writeqb_empty(&qb);
	
	return 0;
}
