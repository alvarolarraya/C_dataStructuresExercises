//Programa: lista_de_pi
//Álvaro Larraya
//21 de octubre de 2019
//Este programa da las aproximaciones a PI de John Wallis desde 0 hasta el número natural introducido
#include <stdio.h>
int i;
float aproximacion_de_pi(int i);
int main()
{
    int n;
    float p;
    char res;
    printf("Programa: lista_de_pi\n");
    printf("Álvaro Larraya\n");
    printf("21 de octubre de 2019\n");
    do
    {
        printf("Este programa da las aproximaciones a PI de John Wallis desde 0 hasta el número natural introducido\n");
        printf("Por favor introduzca un número natural:\n");
        scanf("%d", &n);
        i = 0;
        while (i!=n+1)
        {
            p = aproximacion_de_pi(i);
            p = p*4;
            printf("La aproximacion %d", i);
            printf(" de PI es: %f\n", p);
            i = i+1;
        }
        printf("¿Desea continuar usando el programa?: s/n\n");
        scanf(" %c", &res);
    }while(res == 's' || res == 'S');
    return 0;
}
float aproximacion_de_pi(int i)
{
    float p;
    int k;
    k = 0;
    p = 1;
    while (k!=i)
    {
        if (k!=0)
            p = p*(1-(1.0/((2*k+1)*(2*k+1))));
        k = k+1;
    };
    return p;
}
