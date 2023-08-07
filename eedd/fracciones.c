//Programa: fracciones
//Álvaro Larraya
//21 de octubre de 2019
//Este programa calcula para cada número natural mayor que cero su correspondiente fracción reiterada
#include <stdio.h>
int i,p,q;
void fraccion_reiterada(int i, int *p, int *q);
int main()
{
    int n;
    char res;
    printf("Programa: fracciones\n");
    printf("Álvaro Larraya\n");
    printf("21 de octubre de 2019\n");
    printf("Este programa calcula para cada número natural mayor que cero su correspondiente fracción reiterada \n");
    do 
    {
        printf("Por favor, introduzca un número natural mayor que cero:\n");
        scanf("%d", &n);
        i = 1;
        while (i!=n+1)
        {
            fraccion_reiterada(i,&p,&q);
            printf("La fracción reiterada de %d", i);
            printf(" es: %d", p);
            printf("/%d\n", q);
            i = i+1;
        };
        printf("¿Desea continuar usando el programa?: s/n\n");
        scanf(" %c", &res);
    }while(res == 's' || res == 'S');
    return 0;
}
void fraccion_reiterada(int i, int *p, int *q)
{
    int k,aux;
    k = 1;
    *p = i;
    *q = 1;
    while (k!=i)
    {
        aux = *p;
        *p = *p*(i-k)+*q;
        *q = aux;
        k = k+1;
    };
    return;
}
