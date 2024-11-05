#include <stdio.h>
#include "radix.h"

int getMax(int arr[], int n) {
    int max = arr[0];
    int i;
	for (i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

//countSort
void countSort(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};
    int i;
    
    for (i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    for (i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Radix Sort
void radixSort(int arr[], int n) {
    int m = getMax(arr, n);
    int exp;
    
    for (exp = 1; m / exp > 0; exp *= 10) {
        countSort(arr, n, exp);
    }
}

//print Array
void printArray(int arr[], int n) {
    int i;
	for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}




