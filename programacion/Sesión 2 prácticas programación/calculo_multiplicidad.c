//Programa: calculo_multiplicidad
//Álvaro Larraya
//12 de octubre de 2019
//Este programa calcula la multiplicidad de un número primo como factor del factorial de otro número natural
#include <stdio.h>
int main()
{
    char res;
    int n,q,p,s;
    printf("Programa: calculo_multiplicidad\n");
    printf("Álvaro Larraya\n");
    printf("12 de octubre de 2019\n");
    printf("Este programa calcula la multiplicidad de un número primo como factor del factorial de otro número natural\n");
    do
    {
       printf("Por favor, introduzca un número natural primo: \n");
       scanf(" %d", &p);
       printf("Introduzca un número natural:\n");
       scanf(" %d", &n);
       q = p;
       s = 0;
       while (n>=q)
       {
            s = s+(n/q);
            q = q*p;
       }
       printf("La multiplicidad de %d ", p);
       printf("como factor de %d", n);
       printf("! es: %d \n", s);
       printf("¿Desea continuar usando este programa?: s/n\n");
       scanf(" %c", &res);
    }while(res == 'S' || res == 's');
    return 0;
}
