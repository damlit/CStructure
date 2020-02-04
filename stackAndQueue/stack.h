#ifndef STACK_H
#define STACK_H

typedef
struct stack {
	int data[10];
	int top;
}
Stack;

void init(Stack *);

int stack_empty(Stack *);

void push(Stack *, int);

int pop(Stack *);

void write(Stack *);

void write_empty(Stack *);

void write_int(int popValue);

#endif
