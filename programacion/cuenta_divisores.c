//Programa:cuenta_divisores
//Álvaro Larraya
//17 de noviembre de 2019
/*Este programa pide dos tablas al usuario y cuenta cuántos divisores hay de los elementos de la segunda tabla, en la primera tabla*/
#include <stdio.h>
#define N 5
typedef enum {TRUE = 1, FALSE = 0} boolean;
typedef int tabla[N+1];
tabla g,h;
int cuentadivisores(tabla h, tabla g);
boolean es_divisor(tabla g, int z);
boolean es_divisor(tabla g, int z)
{
    int j;
    boolean b;
    j = 1;
    while (((g[j]%z) != 0)&&(j != N))
        j = j+1;
    b = ((g[j]%z) == 0);
    return b;
}
int cuentadivisores(tabla h, tabla g)
{
    int s,i;
    boolean b;
    s = 0;
    for (i = 1; i < N+1; i = i+1)
    {
        b = es_divisor(g, h[i]);
        if (b == 1)
            s = s+1;
    }
    return s;
}
int main()
{
    int s,i;
    char res;
    printf("Programa:cuenta_divisores\n");
    printf("Álvaro Larraya\n");
    printf("17 de noviembre de 2019\n");
    printf("Este programa pide dos tablas al usuario");
    printf(" y cuenta cuántos divisores");
    printf(" hay de los elementos de la segunda tabla,");
    printf(" en la primera tabla\n");
    do
    {
        printf("Por favor, introduzca los elementos de la primera tabla:\n");
        for (i = 1; i < N+1; i = i+1)
            scanf("%d", &h[i]);
        printf("Por favor, introduzca los elementos de la segunda tabla:\n");
        for (i = 1; i < N+1; i = i+1)
            scanf("%d", &g[i]);
        printf("La primera tabla es: ");
        for (i = 1; i < N; i = i+1)
            printf("%d, ", h[i]);
        printf("%d\n", h[N]);
        printf("La segunda tabla es: ");
        for (i = 1; i < N; i = i+1)
            printf("%d, ", g[i]);
        printf("%d\n", g[N]);
        s = cuentadivisores(h,g);
        printf("Existen %d divisores de la segunda tabla en la primera\n", s);
        printf("¿Desea continuar usando el programa?: s/n => ");
        scanf(" %c", &res);
    }while(res == 's' || res == 'S');
}
