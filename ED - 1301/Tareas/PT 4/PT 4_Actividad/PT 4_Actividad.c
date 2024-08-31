#include <stdio.h>

void Presentacion(){
	printf("\n\n\t--- ARREGLOS UNIDIMENSIONALES ---\n\n");
	
	printf(">Asignatura: Estructura de Datos\n");
	printf(">Semestre: III \t>Grupo: 1301\n\n"); 
	printf(">Objetivo: Realizar un programa en C que genere una lista de los primeros 10 numeros pares, debe imprimirlos en orden inverso. Posteriormente tiene que modificar el valor almacenado en el indice correspondiente al ultimo digito de su numero cuenta por -1.\n\n");
	printf(">Estudiantes y No. Cuenta:\n");
	printf(">>>Benavides Garcia Luis Alberto ---- 319236606.\n");
	printf(">>>Franco Mitzi Natalie Gabrielle --- 424038010.\n\n\n");
			
	system("pause");
	system("cls");
}

void ImprimirInverso(int *arr, int n) {
	int i;
	
    for (i=n-1; i>=0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int pares[10];
    char numeroCuenta[10];
    int i, ultimoDigito;
	
	Presentacion();
	
    //10 números pares
    for (i = 0; i < 10; i++) {
        pares[i] = (i + 1) * 2;
    }

    printf("Nmueros pares en orden inverso:\n");
    ImprimirInverso(pares, 10);

    printf("Ingrese su numero de cuenta (9 digitos): ");
    scanf("%9s", numeroCuenta);

    //Conversión para el último dígito
    ultimoDigito = numeroCuenta[8] - '0';

    //Modificar último dígito por -1
    if (ultimoDigito<10) {
        pares[ultimoDigito] = -1;
    }

    printf("\n Arreglo modificado:\n");
	    for (i=0; i<10; i++) {
	        printf("%d ", pares[i]);
	    }
	    printf("\n\n");

    return 0;
}

