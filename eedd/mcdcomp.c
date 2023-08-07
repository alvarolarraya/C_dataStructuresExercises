//Programa: mcdcomp
//Álvaro Larraya
//9 de octubre de 2019
//Este programa compara la eficiencia de los programas mcd y mcdef
#include <stdio.h>
int main()
{
    int contador,contadoref,a,b,aux;
    int x,y;
    char res;
    printf("Programa: mcdcomp\n");
    printf("Álvaro Larraya\n");
    printf("9 de octubre de 2019\n");
    printf("Este programa compara la eficiencia de los programas mcd y mcdef\n");
    do
    {
        contador = 0;
        contadoref = 0;
        printf("Por favor, introduzca un número entero positivo: \n");
        scanf(" %d", &x);
        printf("Introduzca otro número entero positivo: \n");
        scanf(" %d", &y);
        a = x;
        b = y;
        while (x!=y)
        {    
            contador = contador+1;
            if (x>y)
                x = x-y;
            else
                y = y-x;
        }
        printf("El programa mcd necesita %d iteraciones\n", contador);
        printf("El mcd es: %d\n", x);
        if (a<b)
        {
            aux = b;
            b = a;
            a = aux;
        }
        while (a%b!=0)
        {
            contadoref = contadoref+1;
            aux = b;
            b = a%b;
            a = aux;
        }
        printf("El programa mcdef necesita %d iteraciones\n", contadoref);
        printf("El mcd eficaz es: %d \n", b);
        printf("¿Desea continuar usando este programa?: s/n\n");
        scanf(" %c", &res);
    }while(res == 's' || res == 'S');
    return 0;
}
