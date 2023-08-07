//Programa: repeticiones
//Álvaro Larraya
//14 de noviembre de 2019
/*Este programa comprueba si en una tabla formada por números pedidos al usuario hay elementos en distintas posiciones con el mismo valor*/
#include <stdio.h>
#define N 6
typedef enum {FALSE= 0, TRUE= 1} boolean;
typedef int tabla[N+1];
boolean calcula_A(int tabla[N+1], int x);
boolean elementos_no_repetidos(int tabla[N+1]);
boolean calcula_A(int tabla[N+1], int x)
{
    int y;
    boolean b;
    y = x+1;
    while ((y < N) && (tabla[x] != tabla[y]))
        y = y+1;
    b = (tabla[x] == tabla[y]);
    return b;
}
boolean elementos_no_repetidos(int tabla[N+1])
{
    int x;
    boolean z;
    boolean r;
    x = 0;
    z = calcula_A(tabla, 0);
    while (x < N-1 && z == 0)
    {
        z = calcula_A(tabla, x+1);
        x = x+1;
    }
    r = (z == 0);
    return r;
}
int main(void)
{
    int i;
    boolean r;
    tabla t;
    char res;
    printf("Programa: repeticiones\n");
    printf("Álvaro Larraya\n");
    printf("14 de noviembre de 2019\n");
    printf("Este programa comprueba si en una tabla formada por");
    printf("números pedidos al usuario hay elementos en distintas");
    printf("posiciones con el mismo valor\n");
    do
    {
        printf("Por favor, introduzca 7 elementos enteros en la tabla:\n");
        for(i = 0; i < N+1; i = i+1)
        {
            printf("tabla[%d]: ", i);
            scanf("%d", &t[i]);
        }
        printf("Los números introducidos son: ");
        for(i = 0; i < N; i = i+1)
            printf("%d, ", t[i]);
        printf("%d\n", t[N]);
        r = (elementos_no_repetidos(t) == 0);
        if (r == 0)
            printf("No existen elementos repetidos\n");
        else if (r == 1)
            printf("Existe algún elemento repetido en la tabla\n");
        printf("¿Desea continuar usando el programa?: s/n => ");
        scanf(" %c", &res);
    }while(res == 'S' || res == 's');
    return 0;
}
