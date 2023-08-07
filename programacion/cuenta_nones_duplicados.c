//Programa: cuenta_nones_duplicados
//Álvaro Larraya
//16 de noviembre de 2019
/*Este programa cuenta el número de impares repetidos en dos tablas dadas por el usuario, la primera de 5 valores y la segunda de 7*/
#include <stdio.h>
#define N 5
#define M 7
typedef enum {TRUE = 0, FALSE = 1} boolean;
typedef int tabla1[N+1];
typedef int tabla2[M+1];
tabla1 t;
tabla2 h;
boolean esta_en(int tabla2[M+1], int z);
boolean esta_en(int tabla2[M+1], int z)
{
    int j;
    boolean b;
    j = 1;
    while ((j < M)&&(z != h[j]))
        j = j+1;
    b = (z == h[j]);
    return b;
}
int main()
{
    int i,r;
    char res;
    boolean b;
    printf("Programa: cuenta_nones_duplicados\n");
    printf("Álvaro Larraya\n");
    printf("16 de noviembre de 2019\n");
    printf("Este programa cuenta el número de impares ");
    printf("repetidos en dos tablas dadas por el usuario");
    printf(", la primera de 5 valores y la segunda de 7\n");
    do
    {
        printf("Introduzca los valores de la primera tabla:\n");
        for (i = 1; i < N+1; i = i+1)
            scanf("%d", &t[i]);
        printf("Introduzca los valores de la segunda tabla:\n");
        for (i = 1; i < M+1; i = i+1)
            scanf("%d", &h[i]);
        printf("La primera tabla es: ");
        for (i = 1; i < N; i = i+1)
            printf("%d, ", t[i]);
        printf("%d\n", t[N]);
        printf("La segunda tabla es: ");
        for (i = 1; i < M; i = i+1)
            printf("%d, ", h[i]);
        printf("%d\n", h[N]);
        i = 1;
        r = 0;
        for (i = 1; i<N+1; i = i+1)
        {
            b = esta_en(h,t[i]);
            if ((t[i]%2 == 1)&&(b == 1))
                r = r+1;
            i = i+1;
        }
        printf("Hay %d números impares repetidos en las dos tablas\n", r);
        printf("¿Desea continuar usando el programa?: s/n => ");
        scanf(" %c", &res);
    }while(res == 'S' || res == 's');
}
