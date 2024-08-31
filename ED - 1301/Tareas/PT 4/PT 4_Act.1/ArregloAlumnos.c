#include <stdio.h>
#include <stdlib.h>


void Presentacion(){
	printf("\n\n\t--- Arreglos bidimensionales ---\n\n");
	printf("Objetivo: Realizar un arreglo que acepte datos de alummos.\n\n");
	printf("Estudiantes y No. Cuenta:\n");
	printf(">Benavides Garcia Luis Alberto ---- 319236606.\n");
	printf(">Franco Mitzi Natalie Gabrielle --- 424038010.\n");
	printf(">Semestre: III \t>Grupo: 1301\n");
	printf(">Asignatura: Estructura de Datos\n\n\n"); 
			
	system("pause");
	system("cls");
}

typedef struct {
    char nombre[25];
    int edad;
    int calif;
} Alumno;

void capdatos(int n, Alumno *alumnos, int *sumacalif, int *sumaedad) {
    int i;
    *sumacalif = 0;
    *sumaedad = 0;

    for (i = 0; i < n; i++) {
        printf("\nNombre del alumno %d: ", i + 1);
        scanf("%s", alumnos[i].nombre);

        printf("Edad del alumno %d: ", i + 1);
        scanf("%d", &alumnos[i].edad);

        printf("Calificación del alumno %d: ", i + 1);
        scanf("%d", &alumnos[i].calif);

        *sumacalif += alumnos[i].calif;
        *sumaedad += alumnos[i].edad;
    }

    printf("Datos registrados:\n");
    printf("+-------------------------+------+--------------+\n");
    printf("| Nombre                  | Edad | Calificación |\n");
    printf("+-------------------------+------+--------------+\n");

    for (i = n - 1; i >= 0; i--) {
        printf("| %-23s | %4d | %12d |\n",
               alumnos[i].nombre, alumnos[i].edad, alumnos[i].calif);
    }
    printf("+-------------------------+------+--------------+\n");
}

void promedio(int sumacalif, int sumaedad, int n) {
    float promediocalif;
    float promedioedad;

    if (n > 0) {
        promediocalif = (float)sumacalif / n;
        printf("\nPromedio de calificaciones: %.2f", promediocalif);

        promedioedad = (float)sumaedad / n;
        printf("\nPromedio de edades: %.2f", promedioedad);

    } else {
        printf("No hay alumnos registrados");
    }
}

int main() {
    int n, sumacalif, sumaedad;
    
    Presentacion();

    printf("\tIngrese el número de alumnos: ");
    scanf("%d", &n);

    Alumno *alumnos = (Alumno *)malloc(n * sizeof(Alumno));

    capdatos(n, alumnos, &sumacalif, &sumaedad);
    promedio(sumacalif, sumaedad, n);

    free(alumnos);

    return 0;
}

