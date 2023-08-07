//Programa: ordena3b
//Álvaro Larraya
//4 de octubre de 2019
//Este programa lee tres números enteros y los compara
#include <stdio.h>
int main(void)
{
    int x,y,z;
    int p,s,t,aux;
    char res;
    printf("Programa: ordena3b\n");
    printf("Álvaro Larraya\n");
    printf("4 de octubre de 2019\n");
    printf("Este programa lee tres números enteros y los compara\n");
    do 
    {
        printf("Por favor, introduzca un número entero: \n");
        scanf("%d", &x);
        printf("Introduzca un segundo número entero: \n");
        scanf("%d", &y);
        printf("Introduzca un tercer número entero: \n");
        scanf("%d", &z);
        p = x;
        s = y;
        t = z;
        if (p>s)
        {
            aux = p;
            p = s;
            s = aux;
        }
        if (p>t)
        {
            aux = p;
            p = t;
            t = aux;
        }
        if (s>t)
        {
            aux = s;
            s = t;
            t = aux;
        }
        printf("El mayor valor es: %d \n", t);
        printf("El menor valor es: %d \n", p);
        printf("El valor intermedio es: %d \n", s);
        printf("¿Desea continuar utilizando el programa? s/n: \n");
        scanf(" %c", &res);
    }while(res == 's' || res == 'S');
    return 0;
}
       
    
