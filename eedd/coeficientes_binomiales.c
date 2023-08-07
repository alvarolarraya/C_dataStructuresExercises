//Programa: coeficientes_binomiales
//Álvaro Larraya
//12 de octubre de 2019
//Este programa calcula el número de subconjuntos de m elementos que se pueden hacer en un conjunto de cardinal n
#include <stdio.h>
int main()
{
    int i,n,m,q;
    char res;
    printf("Programa: coeficientes_binomiales\n");
    printf("Álvaro Larraya\n");
    printf("12 de octubre de 2019\n");
    printf("Este programa calcula el número de subconjuntos de m elementos que se pueden hacer en un conjunto de cardinal n\n");
    do
    {
        printf("Por favor, introduzca el número de elementos de los subconjuntos, un número natural: \n");
        scanf(" %d", &m);
        printf("Introduzca el cardinal del conjunto, siendo este mayor que el del número de elementos de los subconjuntos: \n");
        scanf(" %d", &n);
        if (n>=m && m>=0)
        {
            i = 0;
            q = 1;
            while (i!=m)
            {
                q = (q*(n-i))/(i+1);
                i = i+1;
            };
            printf("El número máximo de subconjuntos de %d", m);
            printf(" elementos es: %d\n", q);
        }
        else
            printf("El cardinal del conjunto debe ser un entero mayor que el número de elementos del subconjunto y mayor, o igual, que cero\n");
        printf("¿Desea continuar usando el programa?: s/n\n");
        scanf(" %c", &res);
    }while(res == 's' || res == 'S');
    return 0;
}
