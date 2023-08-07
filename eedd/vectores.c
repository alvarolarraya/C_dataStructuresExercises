/*Programa: vectores
 * Fichero: vectores.c
 * Histórico:
 *  Creado por Álvaro Larraya el 5/2/2020.
 *  versión 1.0.0
 * Copyright © 2016 Álvaro Larraya. All rights reserved.
 */
#include <stdio.h>
#include <math.h>
#define N 10
typedef float vector[N];
/*
 * ACCION: intercambio
 * ENTRADA: a = A y b = B dos valores reales
 * REQUISITOS: Ninguno
 * MODIFICA: a = B y b = A 
 */
void intercambio(float *a, float *b);
/*
 * FUNCION: posicionMaximoEnPrefijo
 * ENTRADA: a un vector de N reales con valores ai= Aiy m = M un entero
 * REQUISITOS: 0<M≤N
 * SALIDA:  el entero pos verificando que pos = I significa que∀k≤M se verifica aI≥ak
 */
int posicionMaximoEnPrefijo(vector a, int M);
/*
 * FUNCION: productoEscalar
 * ENTRADA: v1i = Ai y v2i = Bi
 * REQUISITOS: Ninguno
 * SALIDA:  prod = Σ1≤i≤NAi* Bi
 */
int productoEscalar(vector v1, vector v2);
/*
 * ACCION: ordenaVector
 * ENTRADA: a = vector[N] de reales y ai = Ai
 * REQUISITOS: Ninguno
 * MODIFICA: a contiene los valores iniciales pero ordenados de menor a mayor 
 */
void ordenaVector(vector a);
/*
 * PROGRAMA PRINCIPAL
 * ENTRADA: Por teclado, un vector formado por 10 valores reales
 * REQUISITOS: Ninguno
 * SALIDA: El programa saca por pantalla la diferencia en valor absoluto entre el cuadrado del vector de entrada y el producto escalar del vector de entrada ordenado de menor a mayor y él mismo sin ordenar
 */
int main()
{
    char quiereSalir;
    vector v1,v2;
    float cuadrado_v1,ordenado_por_desordenado;
    int diferencia,i;
    printf("\tPrograma vectores\n");
    printf("\tCreado por Álvaro Larraya");
    printf("El programa saca por pantalla ");
    printf("la diferencia en valor absoluto");
    printf(" entre el cuadrado del vector de ");
    printf("entrada y el producto escalar del");
    printf(" vector de entrada ordenado de ");
    printf("menor a mayor y él mismo sin ordenar\n");
    do
    {
        printf("Inserte 10 valores reales: \n");
        for(i = 0; i < N; i = i+1)
            scanf("%f", &v1[i]);
        cuadrado_v1 = productoEscalar(v1,v1);
        for(i = 0; i < N; i = i+1)
            v2[i] = v1[i];
        ordenaVector(v1);
        ordenado_por_desordenado = productoEscalar(v1,v2);
        diferencia = fabs((ordenado_por_desordenado)-(cuadrado_v1));
        printf("La diferencia entre los dos productos es: %d\n", diferencia);
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
int posicionMaximoEnPrefijo(vector a, int M)
{
    int i,pos;
    pos = 0;
    for(i = 1; i < M+1; i = i+1)
        if(a[pos] < a[i])
            pos = i;
    return pos;
}
int productoEscalar(vector v1, vector v2)
{
    int i,prod;
    prod = 0;
    for(i = 0; i < N; i = i+1)
        prod = prod+(v1[i]*v2[i]);
    return prod;
}
void ordenaVector(vector a)
{
    int i;
    for(i = N-1; i > 1; i = i-1)
        intercambio(&a[i],&a[posicionMaximoEnPrefijo(a,i)]);
    return;
}
