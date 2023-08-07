//Programa:divide_eficiente
//Álvaro Larraya
//Martes 10 de diciembre
/*Este programa realiza la división entre dos números enteros, devolviendo el cociente, el resto y el tiempo de ejecución*/
#include <stdio.h>
void division(int a, int b, int *r, int *q, int *contador);
int main()
{
    int a,b,q,r,contador;
    char res;
    printf("Programa:divide_eficiente\n");
    printf("Álvaro Larraya\n");
    printf("Martes 10 de diciembre\n");
    printf("Este programa realiza la división entre dos ");
    printf("números enteros, devolviendo el cociente, ");
    printf("el resto y el tiempo de ejecución.\n");
    do
    {
        contador = 0;
        printf("Introduzca el dividendo, siendo este entero: ");
        scanf("%d", &a);
        printf("Introduzca el divisor, siendo este entero: ");
        scanf("%d", &b);
        division(a,b,&r,&q,&contador);
        printf("El cociente de la división es: %d", q);
        printf(", y el resto es: %d.\n", r);
        printf("El número de llamadas que se hace a la función división es: %d\n", contador);
        printf("¿Quieres continuar usando el programa?: s/n ");
        scanf(" %c", &res);
    }while(res == 's' || res == 'S');
    return 0;
}
void division(int a, int b, int *r, int *q, int *contador)
{
    int r_2,q_2;
    *contador = *contador+1;
    if (a<b)
    {
        *q = 0;
        *r = a;
    }
    else
    {
        division(a,2*b,&r_2,&q_2,&contador);
        if (b>r_2)
        {
            *q = 2*q_2;
            *r = r_2;
        }
        else
        {
            *q = 2*q_2+1;
            *r = r_2-b;
        }
    }
    return;
}
