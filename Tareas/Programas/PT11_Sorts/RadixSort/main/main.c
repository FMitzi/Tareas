#include <stdio.h>
#include "radix.h"

int main(int argc, char *argv[]) {
    
    int n = argc-1;
    int arr[n];
    int i;
    
    for (i=0;i<n;i++){
    	arr[i] = atoi(argv[i+1]);
    	
	}
     

    printf("\nArray before sorting:\n");
    printArray(arr, n);

    radixSort(arr, n);

    printf("\nArray after sorting:\n");
    printArray(arr, n);

    return 0;
}






