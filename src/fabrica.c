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

int main(){
    
    int idOperario = solicitarIdentificadorOperario();
    time_t tiempoActual = time(NULL);

    struct tm tiempoActualFraccionado = *localtime(&tiempoActual);

    if(strftime(fechaActual, sizeof(fechaActual), "%Y-%m-%d", &tiempoActualFraccionado)!=0){
        printf("\n* La fecha actual es: %s", fechaActual);
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