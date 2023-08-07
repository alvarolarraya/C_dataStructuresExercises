//Programa: mcdef
//Álvaro Larraya
//9 de octubre de 2019
//Este programa calcula el máximo común eficaz de dos números enteros positivos
#include <stdio.h>
int main()
{
    printf("Programa: mcdef\n");
    printf("Álvaro Larraya\n");
    printf("9 de octubre de 2019\n");
    printf("Este programa calcula el máximo común eficaz de dos números enteros positivos\n");
    int x,y,aux;
    char res;
    do
    {
        printf("Por favor, introduzca un número entero positivo:\n");
        scanf(" %d", &x);
        printf("Introduzca otro número entero positivo:\n");
        scanf(" %d", &y);
        if (x<y)
        {
            aux = y;
            y = x;
            x = aux;
        };
        while (x%y!=0)
        {
            aux = y;
            y = x%y;
            x = aux;
        }
        printf("El mcd eficaz de estos dos números es: %d\n", y);
        return 0;
        printf("¿Desea continuar usando el programa?: s/n\n");
        scanf(" %c", &res);
    }while(res == 's' || res == 'S');
}
    
