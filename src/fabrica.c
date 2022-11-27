/*
 * Curso: Acepta este desafio de programación en C
 * Plataforma: LinkedIn Learning
 * Instructor: @EliezerLopez
 * */

// librerias
#include <stdio.h>
#include <time.h>

// variables globales
char fechaActual[15]; 

// prototipos de funciones
int solicitarIdentificadorOperario();
int eligeOpcionMenu();
int generarLogDeHoy();
void introducirError(int idOperario);
void visualizarLog();

int main(){
    
    int idOperario = solicitarIdentificadorOperario();
    
    int logGenerado = generarLogDeHoy();

    int opcionMenu = eligeOpcionMenu();

    switch(opcionMenu){
        case 1: introducirError(idOperario); break;
        case 2: visualizarLog(); break;
        case 3: break;
        case 4: break;
        default: break;
    }

    return 0;
}

// definición de funciones

int solicitarIdentificadorOperario(){
    
    int identificador;
    
    printf("\nIntroduce el identificador del operario: ");
    scanf("%d", &identificador);

    return identificador;
}

int eligeOpcionMenu(){

    puts("\n\nElige una opción:\n");
    printf("1) Introducir error\n");
    printf("2) Visualizar el historial de erorres de hoy\n");
    printf("3) Vaciar historial de errores de hoy\n");
    printf("4) Terminar jornada\n\n");

    int eleccionUsuario;
    printf("Acción: ");
    scanf("%d", &eleccionUsuario);

    return eleccionUsuario;
}

int generarLogDeHoy(){

    FILE *logDeHoy;
    int archivoGeneradoCorrectamente = 0;
    time_t tiempoActual = time(NULL);
    struct tm tiempoActualFraccionado = *localtime(&tiempoActual);

    if(strftime(fechaActual, sizeof(fechaActual), "%Y-%m-%d", &tiempoActualFraccionado)!=0){
        logDeHoy = fopen(fechaActual, "a");
        fclose(logDeHoy);
        archivoGeneradoCorrectamente = 1;
    }

    return archivoGeneradoCorrectamente;
}

void introducirError(int idOperario){

    char error[150];
    puts("Introduce el mensaje de error: ");
    getchar();
    gets(error);

    FILE *logDeHoy = fopen(fechaActual, "a");

    fprintf(logDeHoy, "\n%d - %s\n", idOperario, error);
    fclose(logDeHoy);
}

void visualizarLog(){

    FILE *logDeHoy = fopen(fechaActual,"r");

    puts("\nEl historial de errores de hoy es: \n");

    char caracter;
    while((caracter = fgetc(logDeHoy)) != EOF) printf("%c",caracter);
    printf("\n");
    fclose(logDeHoy);
}