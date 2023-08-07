//Programa: mcd
//Álvaro Larraya
//8 de octubre de 2019
//Este programa calcula el máximo común divisor de dos números enteros positivos
#include <stdio.h>
int main(void)
{
    int x,y;
    char res;
    printf("Programa: mcd\n");
    printf("Álvaro Larraya\n");
    printf("8 de octubre de 2019\n");
    printf("Este programa calcula el máximo común divisor de dos números enteros positivos\n");
    
    do
    {
        printf("Por favor, introduzca un número entero positivo: \n");
        scanf(" %d", &x);
        printf("Por favor, introduzca otro número entero positivo: \n");
        scanf(" %d", &y);
        while (x!=y)
        {
            if (x>y)
                x = x-y;
            else
                y = y-x;
        }
        printf("El mcd de estos dos números es: %d\n", x);
        printf("¿Desea continuar utilizando el programa?\n");
        scanf(" %c", &res);
    }while(res == 's' || res == 'S');
    return 0;
}
