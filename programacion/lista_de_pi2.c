//Programa: lista_de_pi2
//Álvaro Larraya
//22 de octubre de 2019
//Este programa da las primeras n aproximaciones del número PI
#include <stdio.h>
int i,a,b;
float aprox_pi(int i);
int potencia(int a, int b);
int main()
{
    int n;
    char res;
    float pi;
    printf("Programa: lista_de_pi2\n");
    printf("Álvaro Larraya\n");
    printf("22 de octubre de 2019\n");
    printf("Este programa da las primeras n aproximaciones del número PI\n");
    do
    {
        printf("Por favor, introduzca el número de aproximaciones:\n");
        scanf("%d", &n);
        i = 1;
        while (i!=n+1)
        {
            pi = aprox_pi(i);
            pi = pi*4;  
            printf("La aproximación número %d", i);
            printf(" de PI es %f\n", pi);
            i = i+1;
        };
        printf("¿Deseas continuar usando el programa?: s/n\n");
        scanf(" %c", &res);
    }while(res == 's' || res == 'S');
    return 0;
}
int potencia(int a, int b)
{
    int z,c;
    z = 0;
    c = 1;
    while (z!=b)
    {
        c = c*a;
        z = z+1;
    };
    return c;
}
float aprox_pi(int i)
{
    int k,j,y;
    float p;
    k = 0;
    j = 0;
    p = 1;
    while (j!=i)
    {
        k = k*5;
        j = j+1;
        y = potencia(-1,k);
    };
    p = p+(y/(2.0*k+1.0));
    return p;
}
