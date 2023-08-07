//Programa:particion
//Álvaro Larraya
//17 de noviembre de 2019
/*Este programa pide una tabla y un número real al usuario, para crear una permutación de la tabla, en la que a la izquierda de la posición que ocuparía el número se encuentran los valores menores que ese número y a la derecha los mayores*/
#include <stdio.h>
#define N 9
typedef float tabla[N+1];
tabla t,h;
void particion_tabla(tabla t, int x, tabla *h, int *j);
void particion_tabla(tabla t, int x, tabla *h, int *j)
{
    int i;
    float aux;
    i = 0;
    *j = N;
    while (i!=*j)
    {
        if ((t[i] >= x) && (t[*j] < x))
        {
            aux = *h[i];
            *h[i] = *h[*j];
            *h[*j] = aux;
            j = j-1;
        }
        else if ((t[i] >= x) && (t[*j] > x))
            j = j-1;
        else if (((t[i] < x) && (t[*j] >= x)) || ((t[i] < x) && (t[*j] < x)))
            i = i+1;
    };
    return;
}
int main()
{
    int i,j;
    float x;
    char res;
    printf("Programa:particion\n");
    printf("Álvaro Larraya\n");
    printf("17 de noviembre de 2019\n");
    printf("Este programa pide una tabla al usuario y");
    printf(" un número real al usuario, ");
    printf("para crear una permutación de la tabla, en la que");
    printf(" a la izquierda de la posición que ocuparía el número");
    printf(" se encuentran los valores menores que ese número");
    printf(" y a la derecha los mayores\n");
    do
    {
        printf("Por favor, introduzca los valores reales de la primera tabla:\n");
        for (i = 0; i < N+1; i = i+1)
            scanf("%f", &t[i]);
        for (i = 0; i < N+1; i = i+1)
            h[i] = t[i];
        printf("Introduzca el valor del número real: ");
        scanf("%f", &x);
        printf("Los valores de la tabla sin modificar son: ");
        for (i = 0; i < N; i = i+1)
            printf("%f, ", t[i]);
        printf("%f", t[N]);
        particion_tabla(t, x, &h, &j);
        printf("La permutación deseada de la tabla es: ");
        for (i = 0; i < N; i = i+1)
            printf("%f, ", h[i]);
        printf("%f", h[N]);
        printf("La tabla está dividida por la posición %d", j);
        printf(", donde iría %f", x);
        printf("¿Desea continuar usando el programa?: s/n => ");
        scanf(" %c", &res);
    }while(res == 's' || res == 'S');
    return 0;
}
