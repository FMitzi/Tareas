#include <stdlib.h>
#include <stdio.h>

//Intercambiar dos elementos
void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

//Particionar para Quick Sort
int Particion(int* arr[], int low, int high){
	int i,j;    
	int pivot = *arr[high];
	i = (low - 1);

    for(j = low; j <= high - 1; j++){
        if (*arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

//Ahora sí el Quick Sort
void QuickSort(int* arr[], int low, int high){
    if(low < high){
        int pi = Particion(arr, low, high);
        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high);
    }
}

int main(){
    int n,i;
    int** arr;

    printf("¿Cuántos números deseas ingresar?: ");
    scanf("%d", &n);

    arr = (int **)malloc(n * sizeof(int *));
    
	for(i = 0; i < n; i++){
        arr[i] = (int *)malloc(sizeof(int));
        if(arr[i] == NULL){
            return -1;
        }
    }

    printf("Introduce los números:\n");
	printf("Notita: Por favor da un salto de línea por cada cifra diferente que desees ingresar :D.\n\n");  
	
	for(i = 0; i < n; i++){
        scanf("%d", arr[i]);
    }

    QuickSort(arr, 0, n - 1);

    printf("\n Números ordenados:\n");
	
	for(i = 0; i < n; i++){
        printf("%d ", *arr[i]);
        free(arr[i]);
    } printf("\n");
	
	printf("\n\n¡Hasta luego :D !\n\n");
    free(arr);
    return 0;
}
