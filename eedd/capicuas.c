//*Programa: capicuas
 * Fichero: capicuas.c
 * Histórico:
 *  Creado por Álvaro Larraya el 19/2/2020.
 *  versión 1.0.0
 * Copyright © 2016 Álvaro Larraya. All rights reserved.
 */
#include <stdio.h>
# define N 1.008.002
typedef enum {FALSE = 0, TRUE=1} boolean;
/*
 * FUNCION: esCapicua
 * ENTRADA: n un número entero
 * REQUISITOS: 0≤N
 * SALIDA:  el booleano b será verdadero si n era capicúa
 */
boolean esCapicua(long int n);
/*
 * FUNCION: reverso
 * ENTRADA: el entero n = n1n2...nl
 * REQUISITOS: 0≤N
 * SALIDA:  m contiene los dígitos de n invertidos(m = nl...n2n1)
 */
int reverso(long int n);
/*
 * PROGRAMA PRINCIPAL
 * ENTRADA: Por teclado, n un entero menor que 100000
 * REQUISITOS: 0≤N
 * SALIDA: el programa devuelve si n es capicúa o no
 */
int main()
{
    FILE * capicuas.int;
    int x;
    char quiereSalir;
    boolean b;
    printf("\tPrograma capicuas\n");
    printf("\tCreado por Álvaro Larraya");
    printf("\tversion 1.0 (19/02/20)\n\n");
    printf("el programa devuelve si n ");
    printf("es capicúa o no\n");
    do
    {
        capicuas.int = *fopen(*capicuas.int, "wb");
        for (i = 0; i < N+1; i = i+1)
        {
            b = esCapicua(i);
            if (b)
                fwrite(&i, sizeof(long int), 1, capicuas.int);
        }
        printf("¿Quiere continuar usando el programa?: s/n ");
        scanf(" %c", &quiereSalir);
    }while(quiereSalir == 's' || quiereSalir == 'S');
}





boolean esCapicua(long int n)
{
    boolean b;
    b = (n == reverso(n));
    return b;
}
int reverso(long int n)
{
    long int m;
    m = 0;
    while(n>0)
    {
        m = 10*m+n%10;
        n = n/10;
    }
    return m;
}
