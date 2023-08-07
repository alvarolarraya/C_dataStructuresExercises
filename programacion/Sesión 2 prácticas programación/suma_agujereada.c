//Programa: suma_agujereada
//Álvaro Larraya
//8 de octubre de 2019
//Este programa halla la suma agujereada de una base y exponente final determinado
#include <stdio.h>
int main(void)
{
    int n,k;
    float x,s;
    float p,q;
    char res;
    printf("Programa: suma_agujereada\n");
    printf("Álvaro Larraya\n");
    printf("8 de octubre de 2019\n");
    printf("Este programa halla la suma agujereada de una base y esxponente final determinado\n");
    do
    {
        k = 0;
        s = 1;
        p = 1;
        q = 1;
        printf("Introduzca un número entero positivo\n");
        scanf(" %d", &n);
        printf("Introduzca un número entero\n");
        scanf(" %f", &x);
        while (k!=n)
        {
            q = q*x;
            p = p*q;
            s = s+p;
            k = k+1;
        };
        printf("La suma agujereada es: %f\n", s);
        printf("¿Desea continuar utilizando el programa?:s/n\n");
        scanf(" %c", &res);
    }while(res == 's' || res == 'S');
    return 0;
}
