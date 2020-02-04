#ifndef HEAP_H
#define HEAP_H

struct heap;

typedef
struct heap {
	int data[20];
	int length;
	int heap_size;
} Heap;

void heapInit(Heap*, int*, int);

int getParentValue(Heap, int);

int getLeftValue(Heap, int);

int getRightValue(Heap, int);

void buildMaxHeap(Heap*);

int heapMaximum(Heap);

int heapExtractMax(Heap*);

void heapIncreaseKey(Heap*, int, int);

void maxHeapInsert(Heap*, int);

void write(Heap);

void heapsort(int[], int);

void printTable(int[], int);

#endif
