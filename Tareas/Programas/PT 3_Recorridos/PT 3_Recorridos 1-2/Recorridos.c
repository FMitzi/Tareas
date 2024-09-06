#include <stdlib.h>
#include <stdio.h>

void Presentacion(){
	printf("\n\n\t--- Recorrido de Matrices ---\n\n");
	printf("Objetivo: Recorrer las matrices de distintas formas.\n\n");
	printf("Estudiantes y No. Cuenta:\n");
	printf(">Benavides Garcia Luis Alberto ---- 319236606.\n");
	printf(">Franco Mitzi Natalie Gabrielle --- 424038010.\n");
	printf(">Semestre: III \t>Grupo: 1301\n");
	printf(">Asignatura: Estructura de Datos\n\n\n"); 
			
	system("pause");
	system("cls");
}

void RecorreMatrizZ(int MatrizZ[6][6]) {
    int i, j;

    // Recorrido de izquierda a derecha (arriba)
    for (j = 0; j < 6; j++) {
        printf("%d ", MatrizZ[0][j]);
    }

    //Recorrido de la diagonal
    for (i=1; i<6;i++) {
        printf("%d ", MatrizZ[i][6-i-1]);
    }

    //Recorrido de izquierda a derecha (abajo)
    for (j=1; j<6; j++) {
        printf("%d ", MatrizZ[5][j]);
    }

    printf("\n");
}


void RecorreMatrizE(int MatrizE[3][4]) {
    int i, j;
    
    for(i=2; i>=0; i--) {
		for(j=3; j>=0; j--) {
	        printf("%d ", MatrizE[i][j]);
		}
    }
	printf("\n");
}

int main() {
	Presentacion();

    int MatrizZ[6][6] = {
        {10, 11, 12, 13, 14, 15},
        {20, 21, 22, 23, 24, 25},
        {30, 31, 32, 33, 34, 35},
        {40, 41, 42, 43, 44, 45},
        {50, 51, 52, 53, 54, 55},
        {60, 61, 62, 63, 64, 65}
    };
    
    int MatrizE[3][4] = {
        {10, 11, 12, 13},
        {20, 21, 22, 23},
        {30, 31, 32, 33}
    };
	
	printf("----Matriz Z----\n\n");
    RecorreMatrizZ(MatrizZ);
	printf("\n\n----Matriz E----\n\n");
    RecorreMatrizE(MatrizE);
	printf("\n\n");
    system("pause");

    return 0;
}
