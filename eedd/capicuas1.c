/*Programa: capicuas1
 * Fichero: capicuas1.c
 * Histórico:
 *  Creado por Álvaro Larraya el 11/2/2020.
 *  versión 1.0.0
 * Copyright © 2016 Álvaro Larraya. All rights reserved.
 */
#include <stdio.h>
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
    char    quiereSalir;
    long int n;
    boolean b;
    printf("\tPrograma capicuas1\n");
    printf("\tCreado por Álvaro Larraya");
    printf("\tversion 1.0 (11/02/20)\n\n");
    printf("el programa devuelve si n ");
    printf("es capicúa o no\n");
    do
    {
        printf("Inserte un número entero positivo menor que 100000: ");
        scanf("%ld", &n);
        if (n>=0)
        {
            b = (esCapicua(n));
            if (b)
                printf("SÍ es capicúa\n");
            else
                printf("NO es capicúa\n");
        }
        else
        {
            printf("El número introducido es negativo, pruebe otra vez:");
            scanf("%ld", &n);
        }
        printf("¿Desea continuar usando el programa?: s/n ");
        scanf(" %c", &quiereSalir);
    }while(quiereSalir == 's' || quiereSalir == 'S');
    return 0;
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
