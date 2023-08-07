/*Programa: sumMat
 * Fichero: sumMat.c
 * Histórico:
 *  Creado por Álvaro Larraya el 7/2/2020.
 *  versión 1.0.0
 * Copyright © 2016 Álvaro Larraya. All rights reserved.
 */
#include <stdio.h>
#define N 3
typedef float matriz[N][N];
/*
 * ACCION: intercambio
 * ENTRADA: a = A y b = B dos valores reales
 * REQUISITOS: Ninguno
 * MODIFICA: a = B y b = A 
 */
void intercambio(float *a, float *b);
/*
 * ACCION: matrizTraspuesta
 * ENTRADA: m, una tabla de N×N reales con valores mij= Mij
 * REQUISITOS: Ninguno
 * MODIFICA: m de modo que mij pase a contener Mji
 */
void matrizTraspuesta(matriz m);
/*
 * PROGRAMA PRINCIPAL
 * ENTRADA: Por teclado, los valores de dos matrices 3x3
 * REQUISITOS: Ninguno
 * SALIDA: El programa saca por pantalla la suma de las dos matrices y la suma de sus traspuestas
 */
int main()
{
    int i,j;
    char quiereSalir;
    matriz matriz_1,matriz_2;
    printf("\tPrograma sumMat\n");
    printf("\tCreado por Álvaro Larraya");
    printf("\tversion 1.0 (7/02/20)\n\n");
    printf("El programa saca por pantalla");
    printf(" la suma de las dos matrices ");
    printf("y la suma de sus traspuestas\n");
    do
    {
        printf("Inserte los 9 valores de la primera matriz:\n");
        for(i = 0; i < N; i = i+1)
            for(j = 0; j < N; j = j+1)
                scanf("%f", &(matriz_1[i][j]));
        printf("Ahora inserte los 9 valores de la segunda matriz:\n");
        for(i = 0; i < N; i = i+1)
            for(j = 0; j < N; j = j+1)
                scanf("%f", &(matriz_2[i][j]));
        printf("La matriz suma es:\n");
        for(i = 0; i < N; i = i+1)
        {
            for(j = 0; j < N; j = j+1)
                printf("%.2f\t", (matriz_1[i][j]+matriz_2[i][j]));
            printf("\n");
        }
        matrizTraspuesta(matriz_1);
        matrizTraspuesta(matriz_2);
        printf("La traspuesta de la primera matriz es:\n");
        for(i = 0; i < N; i = i+1)
        {
            for(j = 0; j < N; j = j+1)
                printf("%.2f\t", matriz_1[i][j]);
            printf("\n");
        }
        printf("La traspuesta de la segunda matriz es:\n");
        for(i = 0; i < N; i = i+1)
        {
            for(j = 0; j < N; j = j+1)
                printf("%.2f\t", matriz_2[i][j]);
            printf("\n");
        }
        printf("¿Desea continuar usando el programa?: s/n ");
        scanf(" %c",&quiereSalir);
    }while(quiereSalir == 's' || quiereSalir == 'S');
    return 0;
}
void intercambio(float *a, float *b)
{
    float aux;
    aux = *a;
    *a = *b;
    *b = aux;
    return;
}
void matrizTraspuesta(matriz m)
{
    int i,j;
    for(i = 0; i < N-1; i = i+1)
        for(j = i+1; j < N; j = j+1)
            intercambio(&m[i][j],&m[j][i]);
    return;
}
