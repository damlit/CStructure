#include<stdlib.h>
#include<stdio.h>
#include "heap.h"


void heapInit(Heap* H, int tab[], int length) {
	int i;
	H -> length = length;
	H -> heap_size = 0;
	for(i = 0; i < length; i++) {
		H -> data[i] = tab[i];
	}
}

int getParentValue(Heap H, int i) {
	i--;
	if (i == 0) {
		printf("Korzen nie ma parenta!");
		return 0;
	}
	return H.data[((i + 1) / 2) - 1];
}

int getLeftValue(Heap H, int i) {
	int index;
	i--;
	index = ((i + 1) * 2) - 1;
	
	if (index <= 0 || index >= H.length) {
		printf("Wezel nie ma lewego dziecka!");
		return 0;
	}
	return H.data[index];
}

int getRightValue(Heap H, int i) {
	int index;
	i--;	
	index = (i + 1) * 2;
	
	if (index <= 0 || index >= H.length) {
		printf("Wezel nie ma prawego dziecka!");
		return 0;
	}
	return H.data[index];
}

void swapValuesForChild(Heap* H, int childIndex, int i);

void maxHeapify(Heap* H, int i) {
	int rightChildIndex = (i + 1) * 2;
	int leftChildIndex = ((i + 1) * 2) - 1;
	
	if ((H -> data[leftChildIndex] > H -> data[rightChildIndex]) || (rightChildIndex >= H -> length)) {
		swapValuesForChild(H, leftChildIndex, i);
	} 
	else {
		swapValuesForChild(H, rightChildIndex, i);
	}
}

void swapValuesForChild(Heap* H, int childIndex, int i) {
	int tempValue;
	
	if ((childIndex >= 0 && childIndex < H -> length) && (H -> data[childIndex] > H -> data[i])) {
		tempValue = H -> data[childIndex];
		H -> data[childIndex] = H -> data[i];
		H -> data[i] = tempValue;
		maxHeapify(H, childIndex);
	}
}

void buildMaxHeap(Heap* H) {
	int i;
	int lastParentIndex = H -> length / 2;
	H -> heap_size = H -> length;
	for (i = lastParentIndex; i >= 0; i--) {
		maxHeapify(H, i);
	}
}

int heapMaximum(Heap H) {
	return H.data[0];
}

int heapExtractMax(Heap* H) {
	int max = H -> data[0];
	H -> data[0] = H -> data[H -> length - 1];
	H -> length = H -> length - 1;
	H -> heap_size = H -> heap_size - 1;
	buildMaxHeap(H);
	return max;
}

void heapIncreaseKey(Heap* H, int i, int key) {
	i--;
	H -> data[i] = key;
	buildMaxHeap(H);
}

void maxHeapInsert(Heap* H, int key) {
	H -> length = H -> length + 1;
	H -> heap_size = H -> heap_size + 1;
	H -> data[H -> length - 1] = key;
	buildMaxHeap(H);
}

void write(Heap H) {
	int i;
	for (i = 0; i < H.length; i++) {
		printf("%d ", H.data[i]);
	}
	printf("\n");
}

void heapsort(int tab[], int length) {
	int i;
	Heap H;
	heapInit(&H, tab, length);
	buildMaxHeap(&H);
	for (i = 0; i < length; i++) {
		tab[i] = heapExtractMax(&H);
	}
}

void printTable(int* tab, int length) {
	int i;
	for (i = 0; i < length; i++) {
		printf("%d ", tab[i]);
	}
	printf("\n");
}
