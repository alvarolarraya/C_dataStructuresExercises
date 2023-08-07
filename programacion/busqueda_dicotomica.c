//Programa:busqueda_dicotomica
//Álvaro Larraya
//11 de diciembre de 2019
/*Este programa busca  un número en una tabla ordenada dada por el usuario y la posición que tendría en caso de pertenecer a ella.*/
#include <stdio.h>
#define N 10
typedef int tabla[N+1];
int buscar(tabla t, int i, int j, int x);
int main()
{
    int x,i,j,p;
    char res;
    tabla t;
    printf("Programa:busqueda_dicotomica\n");
    printf("Álvaro Larraya\n");
    printf("11 de diciembre de 2019\n");
    printf("Este programa busca  un número en una");
    printf(" tabla ordenada dada por el usuario y");
    printf(" la posición que tendría en caso de");
    printf(" pertenecer a ella.\n");
    do
    {
        printf("Introduzca los valores de la tabla (son 10):\n");
        for (i = 1; i < N+1; i = i+1)
        {
            scanf("%d", &t[i]);
        }
        printf("Introduzca el número entero: ");
        scanf("%d", &x);
        i = 0;
        j = N+1;
        p = buscar(t,i,j,x);
        if (t[p] == x)
        {
            printf("El número se encuentra en la tabla");
            printf(" y ocupa la posición %d\n", p);
        }
        else
        {
            printf("El número no se encuentra en la tabla");
            printf(", pero si lo estuviera ocuparía ");
            printf("la posición: %d\n", p);
        }
        printf("¿Desea continuar usando el programa?: s/n ");
        scanf(" %c", &res);
    }while(res == 's' || res == 'S');
}
int buscar(tabla t, int i, int j, int x)
{
    int p,m;
    if (j == i+1)
        p = i;
    else
    {
        m = (i+j)/2;
        if (x >= t[m])
            p = buscar(t,m,j,x);
        else
            p = buscar(t,i,m,x);
    }
    return p;
}
