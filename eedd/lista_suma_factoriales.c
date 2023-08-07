//Programa:lista_suma_factoriales
//Álvaro Larraya
//12 de diciembre de 2019
/*Este programa pide un número al usuario (n) y devuelve la suma de los factoriales desde 0 hasta n*/
#include <stdio.h>
int s;
int suma_de_factoriales(int n);
int i_suma_de_factoriales(int n,int p,int k,int z);
int main()
{
    char res;
    int i,n;
    printf("Programa:lista_suma_factoriales\n");
    printf("Álvaro Larraya\n");
    printf("12 de diciembre de 2019\n");
    printf("Este programa pide un número al usuario (n) y ");
    printf("devuelve la suma de los factoriales desde");
    printf(" 0 hasta n\n");
    do
    {
        printf("Introduzca el número hasta el que");
        printf(" quiere saber la suma de factoriales\n");
        scanf("%d", &n);
        if (n < 0)
            printf("El número debe ser mayor o igual que cero\n");
        else
        {
            for (i = 0; i < n+1; i = i+1)
            {
                s = suma_de_factoriales(i);
                printf("La suma de factoriales de %d", i);
                printf(" es: %d\n", s);
            }
        }
        printf("¿Desea continuar usando el programa?: s/n ");
        scanf(" %c", &res);
    }while(res == 's' || res == 'S');
}
int suma_de_factoriales(int n)
{
    int i_suma_de_factoriales(int n,int p,int k,int z)
    {
        if (k == n)
            s = p;
        else
        {
                s = i_suma_de_factoriales(n,(p+(z*(k+1))),(k+1),(z*(k+1)));
        }
        return s;
    }
    s = i_suma_de_factoriales(n,1,0,1);
    return s;
}
