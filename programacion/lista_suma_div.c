//Programa:lista_suma_div
//Álvaro Larraya
//20 de octubre de 2019
//Este programa calcula el sumatorio de los divisores de una secuencia de números enteros positivos que comienza por 1
#include <stdio.h>
int i;
int suma_div(int i);
int main()
{
    int n,s;
    char res;
    printf("Programa: lista_suma_div\n");
    printf("Álvaro Larraya\n");
    printf("10 de octubre de 2019\n");
    printf("Este programa calcula el sumatorio de los divisores de una secuencia de números naturales que comienza por 1\n");
    do
    {
        printf("Por favor, introduce un número natural:\n");
        scanf(" %d", &n);
        if (n>=1)
        {
            i = 1;
            while (i!=n+1)
            {
                s = suma_div(i);
                printf("La suma de divisores de %d", i);
                printf(" es %d\n", s);
                i = i+1;
            };
        }
        else
            printf("El número introducido no es un natural, mayor o igual que 1");
        printf("¿Desea continuar usando el programa?: s/n\n");
        scanf(" %c", &res);
    }while(res == 's' || res == 'S');
    return 0;
}
int suma_div(int i)
{
    int s,k;
    k = i;
    s = i;
    while (1<k)
    {
        if (i%(k-1)==0)
            s = s+(k-1);
        k = k-1;
    }
    return s;
}
