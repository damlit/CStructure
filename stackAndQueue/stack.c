#include "stack.h"
#include <stdio.h>

void init(Stack * S) {
	S->top = 0;
}

int stack_empty(Stack * S) {
	if(S->top == 0) {
		return 1;
	}
	return 0;
}

void push(Stack * S, int k) {
	if(S->top < 10) {
		S->data[S->top] = k;
		S->top++;
	}
	else {
		printf("Przepelnienie stosu!\n");
	}
}
	

int pop(Stack * S) {
	int response;
	if(S->top > 0) {
		S->top--;
		response = S->data[S->top];
		S->data[S->top] = 0;
		return response;
	}
	else {
		printf("niedomiar\n");
		return 0;
	}
}


void write(Stack * S) {
	if(S->top != 0) {
		int i;
		for(i = 0; i < (S->top); i++) {
			printf("%d", S->data[i]);
			printf(" ");
		}	
	}
	printf("\n");
}

void write_empty(Stack * S) {
	if(stack_empty(S) == 1) {
		printf("true \n");
	}
	else {
		printf("false \n");
	}
}


void write_int(int value){
	if(value != 0) {
		printf("%d \n", value);
	}
}
