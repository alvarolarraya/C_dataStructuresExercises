//Programa:contador
//Álvaro Larraya
//17 de noviembre de 2019
/*Este programa cuenta parejas de distinto signo, siendo el primer elemento de la pareja negativo y el segundo positivo, en una tabla pedida anteriormente al usuario*/
#include <stdio.h>
#define N 10
typedef int tabla[N+1];
tabla t;
int cuenta_parejas(tabla t);
int cuenta_parejas(tabla t)
{
    int k,r,z;
    k = 1;
    r = 0;
    z = 0;
    while (k != N)
    {
        if (t[k] <= 0)
            z = z+1;
        if (t[k+1] >= 0)
            r = r+z;
        z = 0;
        k = k+1;
    };
    return r;
}
int main ()
{
    int i,parejas;
    char res;
    printf("Programa:contador\n");
    printf("Álvaro Larraya\n");
    printf("17 de noviembre de 2019\n");
    printf("Este programa cuenta parejas de distinto");
    printf(", siendo el primer elemento de la pareja negativo");
    printf("y el segundo positivo,");
    printf(" signo en una tabla pedida anteriormente al usuario\n");
    do
    {
        printf("Por favor, introduzca el contenido de la tabla:\n");
        for (i = 1; i < N+1; i = i+1)
            scanf("%d", &t[i]);
        printf("La tabla introducida es: ");
        for (i = 1; i < N; i = i+1)
            printf("%d, ", t[i]);
        printf("%d\n", t[N]);
        parejas = cuenta_parejas(t);
        printf("El número de parejas de distinto signo es: %d\n", parejas);
        printf("¿Desea continuar usando el programa?: s/n => ");
        scanf(" %c", &res);
    }while(res == 's' || res == 'S');
}
