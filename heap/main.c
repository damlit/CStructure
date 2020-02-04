#include "heap.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
	int tab2[10] = {7, 6, 21, 9, 10, 8, 4, 1, 3, 2};
	
	Heap H;
	int length;
	int tab[10] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
	length = 10;
	
	heapInit(&H, tab, length);
	buildMaxHeap(&H);	
	write(H);
	maxHeapInsert(&H, 15);
	write(H);
	printf("%d\n", heapMaximum(H));
	write(H);
	printf("%d\n", heapExtractMax(&H));
	write(H);
	heapIncreaseKey(&H, 4, 19);
	write(H);
	
	printf("----------------------------------\n");
	printf("Heapsort: \n");
	printf("Tablica przed sortowaniem: \n");
	printTable(tab2, length);
	heapsort(tab2, length);
	printf("Tablica po uzyciu funkcji heapsort: \n");
	printTable(tab2, length);
	
	return 0;
}
