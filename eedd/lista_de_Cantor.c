//Programa: lista_de_Cantor
//Álvaro Larraya
//20 de octubre de 2019
//Este programa hace corresponder a cada número racional, de una secuencia de racionales empezando por 1, un número entero.
#include <stdio.h>
int m,n,j,i;
void inversa_de_Cantor(int i, int *m, int *n, int *j);
int main()
{
    int r;
    char res;
    printf("Programa: lista_de_Cantor\n");
    printf("Álvaro Larraya\n");
    printf("20 de octubre de 2019\n");
    printf("Este programa hace corresponder a cada número racional un número entero.\n");
    do
    {
        printf("Por favor, introduzca un número entero positivo: \n");
        scanf(" %d", &r);
        i = 0;
        while (i!=r+1)
        {
            inversa_de_Cantor(i,&m,&n,&j);
            printf("A %d", i);
            printf(" le corresponde una m: %d", m);
            printf(" y una n: %d", n);
            printf(". Su inversa de Cantor es: %d\n", j);
            i = i+1;
        };
        printf("¿Desea continuar usando el programa?: s/n\n");
        scanf(" %c", &res);
    }while(res == 's' || res == 'S');
    return 0;
}
void inversa_de_Cantor(int i, int *m, int *n, int *j) 
{
    int s;
    s = 0;
    while (i>= ((1.0/2.0)*(s+1)*(s+2)))
        s = s+1;
    *m = i-((1.0/2.0)*s*(s+1));
    *n = s-i+((1.0/2.0)*s*(s+1));
    *j = (1.0/2.0)*(*m+*n)*(*m+*n+1)+*m;
    return;
}
