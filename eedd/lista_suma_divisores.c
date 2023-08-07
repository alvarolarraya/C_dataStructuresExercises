//Programa:lista_suma_divisores
//Álvaro Larraya
//12 de diciembre de 2019
/*Este programa calcula el número de divisores de una variable que aumenta su valor desde 0 hasta un entero dado por el usuario*/
#include <stdio.h>
int s;
int suma_divisores(int n);
int i_suma_divisores(int n, int p, int k);
int main()
{
    int n,i;
    char res;
    printf("Programa:lista_suma_divisores\n");
    printf("Álvaro Larraya\n");
    printf("12 de diciembre de 2019\n");
    printf("Este programa calcula el número de divisores");
    printf(" de una variable que aumenta su valor");
    printf(" desde 0 hasta un entero dado");
    printf(" por el usuario\n");
    do
    {
        printf("Introduzca el número hasta el cual quiere saber");
        printf(" sus divisores: ");
        scanf("%d", &n);
        if (n < 1)
            printf("El número debe ser mayor o igual a uno\n");
        else
        {
            for (i = 1; i < n+1; i = i+1)
            {
                s = suma_divisores(i);
                printf("Los divisores de %d", i);
                printf(" suman: %d\n", s);
            }
        }
        printf("¿Desea continuar usando el programa?: s/n ");
        scanf(" %c", &res);
    }while(res == 's' || res == 'S');
    return 0;
}
int suma_divisores(int n)
{
    int i_suma_divisores(int n, int p, int k)
    {
        if (k == n)
            s = p;
        else
        {
            if (n%(k+1) == 0)
                s = i_suma_divisores(n,p+(k+1),(k+1));
            else
                s = i_suma_divisores(n,p,(k+1));
        }
        return s;
    }
    s = i_suma_divisores(n,1,1);
    return s;
}
