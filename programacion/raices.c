//Programa: raices
//Álvaro Larraya
//21 de octubre de 2019
//Este programa calcula los valores que elevados a n están justo por encima y justo por debajo de un número natural mayor que 0
#include <stdio.h>
int x,i,a,b;
int raiz_n_esima(int x, int i);
int potencia(int a, int b);
int main()
{
    int n,y;
    char res;
    printf("Programa: raices\n");
    printf("Álvaro Larraya\n");
    printf("21 de octubre de 2019\n");
    printf("Este programa calcula los valores cuya raíz n-ésima están justo por encima y justo por debajo de un número natural mayor que 0\n");
    do
    {
        printf("Por favor, introduzca un número natural:\n");
        scanf("%d", &x);
        printf("Introduzca un número natural mayor que 0:\n");
        scanf("%d", &n);
        i = 1;
        while (i!=n+1)
        {
            y = raiz_n_esima(x,i);
            printf("Cuando la base es %d", x);
            printf(" y el exponente es %d", i);
            printf(" el valor buscado es %d\n", y);
            i = i+1;
        };
        printf("¿Desea continuar usando el programa?: s/n\n");
        scanf(" %c", &res);
    }while(res == 's' || res == 'S');
    return 0;
}
int raiz_n_esima(int x, int i)
{
    int y,z;
    y = 1;
    z = potencia(2,i);
    while (x>=z)
    {
        y = y+1;
        z = potencia(y+1,i);
    };
    return y;
}
int potencia(int a, int b)
{
    int p,c;
    p = 0;
    c = 1;
    while (p!=b)
    {
        c = c*a;
        p = p+1;
    };
    return c;
}
