//Programa:lista_suma_div
//Álvaro Larraya
//20 de octubre de 2019
//Este programa calcula el sumatorio de los divisores de una secuencia de números enteros positivos que comienza por 1
#include <stdio.h>
int n
int suma_div(int n)
int main()
{
    int i,s,
    printf("Programa: lista_suma_div\n");
    printf("Álvaro Larraya\n");
    printf("10 de octubre de 2019\n");
    printf("Este programa calcula el sumatorio de los divisores de una secuencia de números enteros positivos que comienza por 1\n");
    do
    {
        printf("Por favor, introduce un número entero positivo:\n");
        scanf(" %d", &n);
        i = 0;
        while (i!=n)
        {
            s = suma_div(i);
            printf("La suma de divisores de %d", i);
            printf(" es %d", s);
            i = i+1;
        }
    }while(res == 's' || res == 'S');
    return 0;
}
int suma_div(int n)
{
    int i,s,k;
    k = i;
    s = i;
    while (k!=1)
    {
        if (i%(k-1) == 0)
            s = s+k-1;
            k = k-1;
    }
    return s;
}
