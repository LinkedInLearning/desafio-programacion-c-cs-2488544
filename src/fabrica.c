/*
 * Curso: Acepta este desafio de programación en C
 * Plataforma: LinkedIn Learning
 * Instructor: @EliezerLopez
 * */

// librerias
#include <stdio.h>

// variables globales

// prototipos de funciones
int solicitarIdentificadorOperario();

int main(){
    
    int idOperario = solicitarIdentificadorOperario();
    
    return 0;
}

// definición de funciones

int solicitarIdentificadorOperario(){
    
    int identificador;
    
    printf("\nIntroduce el identificador del operario: ");
    scanf("%d", &identificador);

    return identificador;
}