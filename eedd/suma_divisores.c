//Programa: suma_divisores
//Álvaro Larraya
//10 de octubre de 2019
//Este programa calcula el sumatorio de los divisores de un número entero positivo
#include <stdio.h>
int main()
{
    printf("Programa: suma_divisores\n");
    printf("Álvaro Larraya\n");
    printf("10 de octubre de 2019\n");
    printf("Este programa calcula el sumatorio de los divisores de un número entero positivo\n");
    int n,s,k;
    char res;
    do
    {
        printf("Por favor, introduce un número entero positivo: %d \n");
        scanf(" %d", &n);
        k = n;
        s = n;
        while (k!=1)
        {
            if (n%(k-1) == 0)
                s = s+k-1;
            k = k-1;
            printf("El sumatorio de los divisores del número introducido es: %d", s);
            printf("¿Desea continuar usando el programa?: s/n\n");
            scanf(" %c", &res);
        }
    }while(res == 's' || res == 'S');
    return 0;
}
