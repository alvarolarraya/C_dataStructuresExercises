//Programa:lista_coeficientes
//Álvaro Larraya
//Jueves 12 de diciembre
/*Este programa halla el número de subconjuntos que se pueden formar de 0-m elementos en un conjunto de cardinal n*/
#include <stdio.h>
int coeficientes_binomiales(int n, int m);
int main()
{
    int n,m,q,i;
    char res;
    printf("Programa:lista_coeficientes\n");
    printf("Álvaro Larraya\n");
    printf("Jueves 12 de diciembre\n");
    printf("Este programa halla el número de subconjuntos");
    printf(" que se pueden formar de m elementos en");
    printf(" un conjunto de cardinal n\n");
    do
    {
        printf("Introduzca el cardinal del conjunto: ");
        scanf("%d", &n);
        printf("Introduzca los elementos que tendrán");
        printf(" los subconjuntos: ");
        scanf("%d", &m);
        if (n>m)
        {
            for (i = 0; i < m+1; i = i+1)
            {    
                q = coeficientes_binomiales(n,i);
                printf("El coeficiente binomial de %d ", n);
                printf("sobre %d ", i);
                printf("es %d\n", q);
            }
        }
        else
        {
            printf("El cardinal del conjunto debe ");
            printf("ser igual o mayor que el número ");
            printf("de elementos de los subconjuntos\n");
        }
        printf("¿Desea continuar usando el programa?: s/n ");
        scanf(" %c", &res);
    }while(res == 's' || res == 'S');
    return 0;
}
int coeficientes_binomiales(int n, int m)
{
    int q,q_2;
    if (m == 0)
        q = 1;
    else
    {
        q_2 = coeficientes_binomiales(n,m-1);
        q = (q_2*(n-m+1))/m;
    }
    return q;
}
