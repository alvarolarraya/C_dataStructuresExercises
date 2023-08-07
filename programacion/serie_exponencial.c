//Programa: serie_exponencial
//Álvaro Larraya
//18 de octubre de 2019
// Este programa calcula el sumatorio de las potencias de la misma base y exponente hasta n
#include <stdio.h>
int a,b,i;
int potencia(int a, int b);
int serie_exponencial(int i);
int main()
{
    int i,n,serie;
    char res;
    printf("Programa: serie_exponencial\n");
    printf("Álvaro Larraya\n");
    printf("18 de octubre de 2019\n");
    printf("Este programa calcula el sumatorio de las potencias de la misma base y exponente hasta n\n");
    do
    {
        printf("Por favor, introduzca un número natural: \n");
        scanf("%d", &n);
        if (n>=0)
        {
            i = 0;
            while (i!=n)
            {
                i = i+1;
                serie = serie_exponencial(i);
                printf("La serie exponencial de %d", i);
                printf(" es: %d\n", serie);
            };
        }
        else
            printf("El número introducido no es natural\n");
        printf("¿Desea continuar usando el programa?: s/n\n");
        scanf(" %c", &res);
        
    }while(res == 's' || res == 'S');
    return 0;
}
int potencia(int a,int b)
{
    int c,p;
    c = 1;
    p = 0;
    while (p!=b)
    {
        c = c*a;
        p = p+1;
    }
    return c;
}
int serie_exponencial(int i)
{
    int s,j,aux;
    j = 1;
    s = 1;
    while (j!=i)
    {
        aux = potencia(j+1,j+1);
        s = s+aux;
        j = j+1;
    };
    return s;
}


