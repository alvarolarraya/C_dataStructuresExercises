//Programa: compara3
//Álvaro Larraya
//4 de octubre de 2019
//Este programa compara tres numeros enteros y dice cual es el mayor, el menor y el intermedio
#include <stdio.h>
int main(void)
{
    int x,y,z;
    int p,s,t;
    char res;
    printf("Programa: compara3 \n");
    printf("Álvaro Larraya \n");
    printf("4 de octubre de 2019 \n");
    printf("Este programa compara tres numeros enteros, diciendo cuál es el mayor, el menor y el intermedio \n");
    do
    {
        printf("Por favor, introduzca un número entero: \n");
        scanf("%d", &x);
        printf("Introduzca un segundo número entero: \n");
        scanf("%d", &y);
        printf("Introduzca un tercer número entero: \n");
        scanf("%d", &z);
        if (x<=y)
            if (y<z)
            {
                p = x;
                s = y;
                t = z;
            }
            else if ((y>=z)&&(z>=x))
            {
                p = x;
                s = z;
                t = y;
            }
            else
            {
                p = z;
                s = x;
                t = y;
            }
        else
            if (x<z)
            {
                p = y;
                s = x;
                t = z;
            }
            else if ((y<=z)&&(z<=x))
            {
                p = y;
                s = z;
                t = x;
            }
            else
            {
                p = z;
                s = y;
                t = x;
            }
        printf("El valor más pequeño es: %d, ", p);
        printf("el segundo más pequeño es: %d", s);
        printf(" y el mayor de todos es: %d\n", t);
        printf("¿Desea continuar utilizando el programa?: s/n\n");
        scanf(" %c", &res);
    }while(res == 's' || res == 'S');
    return 0;
}
