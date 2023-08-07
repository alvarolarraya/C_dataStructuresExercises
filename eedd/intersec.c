/*Programa: intersec
 * Fichero: intersec.c
 * Histórico:
 *  Creado por Álvaro Larraya el 26/2/2020.
 *  versión 1.0.0
 * Copyright © 2016 Álvaro Larraya. All rights reserved.
 */
#include <stdio.h>
#define N 1008002
char nombre[100];
typedef enum {FALSE = 0, TRUE=1} boolean;
/*
 * PROGRAMA PRINCIPAL
 * ENTRADA: la ruta de dos fiheros metidas por teclado
 * REQUISITOS: que los ficheros tengan al menos un entero cada uno
 * SALIDA: el programa crea un fichero con todos los enteros pertenecientes a los dos ficheros ordenados de menor a mayor
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
