//Programa:segmentos
//Álvaro Larraya
//17 de noviembre de 2019
/*Este programa solicita dos tablas al usuario y dice cual de las dos posee la mayor suma máxima de sus elementos*/
#include <stdio.h>
#define N 7
typedef int tabla[N+1];
tabla t,h;
int segmento_maximo(tabla a);
int max(int b, int c);
int max(int b, int c)
{
    int mayor;
    if (b > c)
        mayor = b;
    else
        mayor = c;
    return mayor;
}
int segmento_maximo(tabla a)
{
    int x,z,r,mayor;
    x = 1;
    r = a[1];
    z = a[1];
    while (x != N+1)
    {
        r = max(r,z);
        mayor = max(z,0);
        z = mayor+a[x+1];
        x = x+1;
    }
    return r;
}
int main()
{
    int i,suma1,suma2;
    char res;
    printf("Programa:segmentos\n");
    printf("Álvaro Larraya\n");
    printf("17 de noviembre de 2019\n");
    printf("Este programa solicita dos tablas al usuario ");
    printf("y dice cual de las dos posee la mayor");
    printf(" suma máxima de sus elementos\n");
    do
    {
        printf("Introduzca los elementos de la primera tabla:\n");
        for (i = 1; i < N+1; i = i+1)
            scanf("%d", &t[i]);
        printf("Introduzca los elementos de la segunda tabla:\n");
        for (i = 1; i < N+1; i = i+1)
            scanf("%d", &h[i]);
        suma1 = segmento_maximo(t);
        suma2 = segmento_maximo(h);
        printf("La suma máxima de la tabla 1 es: %d", suma1);
        printf(", mientras que la de la tabla 2 es: %d\n", suma2);
        if (suma1 < suma2)
            printf("Luego la segunda tabla tiene una suma máxima mayor\n");
        else if (suma1 > suma2)
            printf("Luego la primera tabla tiene una suma máxima mayor\n");
        else
            printf("Luego la suma máxima de las dos tablas es idéntica\n");
        printf("¿Desea continuar usando el programa?: s/n => ");
        scanf(" %c", &res);
    }while(res == 's' || res == 'S');
}
