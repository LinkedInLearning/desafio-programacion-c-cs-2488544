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

int main(){
    
    int idOperario = solicitarIdentificadorOperario();
    time_t tiempoActual = time(NULL);

    struct tm tiempoActualFraccionado = *localtime(&tiempoActual);

    if(strftime(fechaActual, sizeof(fechaActual), "%Y-%m-%d", &tiempoActualFraccionado)!=0){
        printf("\n* La fecha actual es: %s", fechaActual);
    }

    int opcionMenu = eligeOpcionMenu();

    switch(opcionMenu){
        case 1: break;
        case 2: break;
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