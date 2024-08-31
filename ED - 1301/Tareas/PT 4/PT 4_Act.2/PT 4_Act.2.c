#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Presentacion(){
	printf("\n\n\t--- ARREGLOS BIDIMENSIONALES ---\n\n");
	
	printf(">Asignatura: Estructura de Datos\n");
	printf(">Semestre: III \t>Grupo: 1301\n\n"); 
	printf(">Objetivo.2: Genere un arreglo dinamico variable bidimensional de acuerdo a su numero de cuenta y sera rellenado con los digitos correspondientes a su cuenta. El arreglo debe solicitar el numero de cuenta.\n\n");
	printf(">Estudiantes y No. Cuenta:\n");
	printf(">>>Benavides Garcia Luis Alberto ---- 319236606.\n");
	printf(">>>Franco Mitzi Natalie Gabrielle --- 424038010.\n\n\n");
			
	system("pause");
	system("cls");
}

void Arreglo(int *cuenta, int longitud) {
	
	int i, j, digito;//i: ciclos interiores, j:c. exteriores
    for (i=0; i<longitud; i++) {
        digito = cuenta[i];
    //Se asigna memoria para que lla fila tenga tantos elemtos como el dígito
		int *fila = (int *)malloc(digito * sizeof(int));
        if (fila == NULL) {
            printf("Error al asignar memoria.\n");
            exit(1);//El prog, terminará inmediatamente si osurre un error
        }
        
    //Recorre la fila y da el valor del díg. a cada elemto
        for (j=0; j<digito; j++) {
            fila[j] = digito;
        }
        
        for (j=0; j<digito; j++) {
            printf("%d ", fila[j]);
        }
        
        printf("\n");
        free(fila);
    }
}

int main() {
    char numeroCuenta[10];
    int i;
    
    Presentacion();
    
    printf("Ingrese su numero de cuenta (9 digitos): ");
    scanf("%9s", numeroCuenta);
    //%9s evita desbordamiento
    
//Captura la longitud del número de cuenta
    int longitud = strlen(numeroCuenta);
	
    int *cuenta = (int *)malloc(longitud * sizeof(int));
    if (cuenta == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }
//Almacenar en el arreglo
    for (i=0; i<longitud; i++) {
        cuenta[i] = numeroCuenta[i] - '0';//Conversión de char a int
    }

    Arreglo(cuenta, longitud);

    free(cuenta);
    return 0;
}

