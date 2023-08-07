#define N 5
#include <stdio.h>
typedef enum {FALSE = 0, TRUE = 1} boolean;
typedef int tabla[N+1];
tabla t,h;
boolean son_ortogonales();
boolean son_ortogonales(tabla t, tabla h)
{
    int k,z;
    boolean b;
    k = 1;
    z = 0;
    while (k<N+1)
    {
        z = z+t[k+1]*h[k+1];
        k = k+1;
    }
    if (z == 0)
        b = 1;
    else if ( z == 1)
        b = 0;
    return b;
}
int main()
{
    int i;
    boolean b;
    printf("Por favor, introduzca los 5");
    printf(" valores de la primera tabla: \n");
    for(i = 1; i < N+1; i = i+1)
    {
        printf("tabla1[%d]: ", i);
        scanf("%d", &t[i]);
    }
    printf("Por favor, introduzca los 5");
    printf(" valores de la segunda tabla: \n");
    for(i = 1; i < N+1; i = i+1)
    {
        printf("tabla2[%d]: ", i);
        scanf("%d", &h[i]);
    }
    printf("La tabla 1 es: ");
    for(i = 1; i < N; i = i+1)
        printf("%d, ", t[i]);
    printf("%d\n", t[N]);
    printf("La tabla 2 es: ");
    for(i = 1; i < N; i = i+1)
        printf("%d, ", h[i]);
    printf("%d\n", h[N]);
    b = (son_ortogonales(t,h) == 1);
    if (b == 0)
        printf("Las tablas SÍ son ortogonales\n");
    else if (b == 1)
        printf("Las tablas NO son ortogonales\n");
    return 0;
}
