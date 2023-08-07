/*Programa: primos
 * Fichero: primos.c
 * Histórico:
 *  Creado por Álvaro Larraya el 26/2/2020.
 *  versión 1.0.0
 * Copyright © 2016 Álvaro Larraya. All rights reserved.
 */
#include <stdio.h>
#define N 1008002
typedef enum {FALSE = 0, TRUE=1} boolean;
/*
 * FUNCION: esPrimo
 * ENTRADA: n= N, un numero entero
 * REQUISITOS: 1<N
 * SALIDA:  el booleano b sera verdadero si N es primo
 */
boolean esPrimo(long int n);
/*
 * PROGRAMA PRINCIPAL
 * ENTRADA: Ninguno
 * REQUISITOS: Ninguno
 * SALIDA: el programa crea un fichero con todos los primos menores que 1008002 y lo imprime en pantalla
 */
int main()
{
    FILE * f;
    long int i;
    char quiereSalir;
    boolean b;
    do
    {
        f = fopen("primos.int", "wb");
        for (i = 2; i < N+1; i = i+1)
        {
            b = (esPrimo(i));
            if (b)
                fwrite(&i, sizeof(long int), 1, f);
        }
        fclose(f);
        printf("Ya se ha creado el fichero y es:\n");
        f = fopen("primos.int", "rb");
        fread(&i, sizeof(long int), 1, f);
        while (!feof(f))
        {
            printf("%ld ", i);
            fread(&i, sizeof(long int), 1, f);
        }
        fclose(f);
        printf("\n¿Quiere volver a ejecutar el programa?: s/n ");
        scanf(" %c", &quiereSalir);
    }while(quiereSalir == 's' || quiereSalir == 'S');
}
boolean esPrimo(long int n)
{
    long int k;
    boolean b;
    if (n == 2)
        b = 1;
    else if (n == 3)
        b = 1;
    else
        if (n%2 == 0)
            b = 0;
        else
        {
            k = 3;
            while ((n > k*k) && (n%k != 0))
                k = k+2;
            b = n%k != 0;
        }
    return b;
}
