//Programa: inversa_de_Cantor
//Álvaro Larraya
//11 de octubre de 2019
//Este programa hace corresponder a cada número racional un número entero.
#include <stdio.h>
int main()
{
    int r,m,n,s,j;
    char res;
    printf("Programa: inversa_de_Cantor\n");
    printf("Álvaro Larraya\n");
    printf("11 de octubre de 2019\n");
    printf("Este programa hace corresponder a cada número racional un número entero.\n");
    do
    {
        printf("Por favor, introduzca un número entero positivo: \n");
        scanf(" %d", &r);
        s = 0;
        while (r>= ((1.0/2.0)*(s+1)*(s+2)))
            s = s+1;
        printf("A %d", r);
        m = r-((1.0/2.0)*s*(s+1));
        n = s-r+((1.0/2.0)*s*(s+1));
        printf("le corresponde una m= %d \n", m);
        printf("y una n= %d \n", n);
        j = (1.0/2.0)*(m+n)*(m+n+1)+m;
        printf("La función inversa es= %d \n", j);
        printf("¿Desea continuar usando el programa?:\n");
        scanf(" %c", &res);
    }while(res == 's' || res == 'S');
    return 0;
}
