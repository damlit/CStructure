#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillNotDescendingTable(int table[], int size);
void fillRandomTable(int table[], int size);
void fillNotAscendingTable(int table[], int size);
int getSize(int size);
void printValuesForFirstTable(int table[]);
void runSorts(int table[], int size, char type);
void getCopyOfTable(int copyOfTable[], const int table[], int size);
void bubbleSort(int table[], int size);
void swap(int *xp, int *yp);
void insertSort(int table[], int size);
void mergeSort(int i, int j, int a[], int aux[]);

int main() {
    int * tab;
    int size;
    srand((unsigned) time(NULL));
    for(size = 10; size < 100000000; size = size * 10) {
    	tab = (int *) calloc(size, sizeof(int));
        printf("rozmiar 10^%d \n", getSize(size));
        fillNotDescendingTable(tab, size);
        runSorts(tab, size, 'f');
        fillRandomTable(tab, size);
        runSorts(tab, size, 's');
        fillNotAscendingTable(tab, size);
        runSorts(tab, size, 't');
        free(tab);
    }
    return 0;
}

int getSize(int size) {
    int power = 0;
    while(size != 1) {
        if((size % 10 == 0)) {
            power++;
            size = size/10;
        }
    }
    return power;
}

void fillNotDescendingTable(int table[], int size) {
    int i;
	printf("niemalejaco: \n");
    for(i = 0; i < size; i++) {
        table[i] = i;
    }
    if(size == 10) {
        printValuesForFirstTable(table);
    }
}

void printValuesForFirstTable(int table[]) {
	int i;
    for(i = 0; i < 10; i++) {
        printf("%d ", table[i]);
    }
    printf("\n");
}

void fillRandomTable(int table[], int size) {
	int i;
	printf("losowo: \n");
    for(i = 0; i < size; i++) {
        table[i] =  rand() % 100 + 1;
    }
    if(size == 10) {
        printValuesForFirstTable(table);
    }
}

void fillNotAscendingTable(int table[], int size) {
    int i;
	printf("nierosnaco: \n");
    for(i = 0; i < size; i++) {
        table[i] = size - i;
    }
    if(size == 10) {
        printValuesForFirstTable(table);
    }
}

void runSorts(int table[], int size, char type) {
    int *copyOfTable = (int *) calloc(size, sizeof(int));
    clock_t start, stop;
    double time;
	getCopyOfTable(copyOfTable, table, size);

    if(size > 100000) {
        printf("BUBBLE-SORT: 60+ \n");
    }
    else {
        start = clock();
       bubbleSort(copyOfTable, size);
        stop = clock();
        time = (stop - start)/(double)CLOCKS_PER_SEC;
        printf("BUBBLE-SORT: %.1f \n", time);
        if(size == 10) {
            printValuesForFirstTable(copyOfTable);
        }
    }

    if(size > 100000 && (type == 's' || type == 't')) {
        printf("INSERT-SORT: 60+ \n");
    }
    else {
        getCopyOfTable(copyOfTable, table, size);
        start = clock();
        insertSort(copyOfTable, size);
        stop = clock();
        time = (stop - start)/(double)CLOCKS_PER_SEC;
        printf("INSERT-SORT: %.1f \n", time);
        if(size == 10) {
            printValuesForFirstTable(copyOfTable);
        }
    }
    
    start = clock();
    mergeSort(0, size, table, copyOfTable);
    stop = clock();
    time = (stop - start)/(double)CLOCKS_PER_SEC;
    printf("MERGE-SORT: %.1f \n", time);
    if(size == 10) {
        printValuesForFirstTable(copyOfTable);
    }
    
    free(copyOfTable);
}

void getCopyOfTable(int copyOfTable[], const int table[], int size) {
	int i;
    for(i = 0; i < size; i++) {
        copyOfTable[i] = table[i];
    }
}

void bubbleSort(int table[], int size) {
    int i, j;
    for (i = 0; i < size-1; i++) {
        for (j = 0; j < size-i-1; j++) {
            if (table[j] > table[j+1]) {
                swap(&table[j], &table[j+1]);
            }
        }
    }
}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void insertSort(int table[], int size)
{
    int i, key, j;
    for (i = 1; i < size; i++) {
        key = table[i];
        j = i - 1;
        while (j >= 0 && table[j] > key) {
            table[j + 1] = table[j];
            j = j - 1;
        }
        table[j + 1] = key;
    }
}

void mergeSort(int i, int j, int tab[], int cTab[]) {
	int ptr_r;
	int ptr_l;
	int mid;
	int k;
    if (j <= i) {
        return;  
    }
    mid = (i + j) / 2;
    
    mergeSort(i, mid, tab, cTab);    
    mergeSort(mid + 1, j, tab, cTab);    

    ptr_l = i;    
    ptr_r = mid + 1;     
        

    for (k = i; k <= j; k++) {
        if (ptr_l == mid + 1) {     
            cTab[k] = tab[ptr_r];
            ptr_r++;
        } else if (ptr_r == j + 1) {      
            cTab[k] = tab[ptr_l];
            ptr_l++;
        } else if (tab[ptr_l] < tab[ptr_r]) {   
            cTab[k] = tab[ptr_l];
            ptr_l++;
        } else {    
            cTab[k] = tab[ptr_r];
            ptr_r++;
        }
    }
    for (k = i; k <= j; k++) {     
        tab[k] = cTab[k];
    }
}
