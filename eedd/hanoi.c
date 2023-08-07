//Programa:hanoi
//Álvaro Larraya
//10 de diciembre de 2019
/*Este programa nos guía paso a paso para poder llevar a cabo el rompecabezas: Las torres de Hanoi, con n anillos y queriendo llevar los anillos del poste A al B con C como auxiliar*/
#include <stdio.h>
void colocar(int n,char i,char j,char k,int *contador);
int main()
{
    char res,i,j,k;
    int n,contador;
    printf("Programa:hanoi\n");
    printf("Álvaro Larraya\n");
    printf("10 de diciembre de 2019\n");
    printf("Este programa nos guía paso a paso ");
    printf("para poder llevar a cabo el rompecabezas: ");
    printf("Las torres de Hanoi, con n anillos");
    printf(" y queriendo llevar los anillos del poste");
    printf(" A al B con C como auxiliar\n");
    do
    {
        contador = 0;
        i = 'A';
        j = 'B';
        k = 'C';
        printf("Introduzca con cuantos discos desea jugar: ");
        scanf("%d",&n);
        printf("Con ese número de discos los pasos son:\n");
        colocar(n,i,j,k,&contador);
        printf("Por tanto los pasos necesarios son %d\n", contador);
        printf("¿Desea continuar usando el programa?: s/n \n");
        scanf(" %c", &res); 
    }while(res == 's' || res == 'S');
    return 0;
}
void colocar(int n,char i,char j,char k,int *contador)
{
    if (n == 1)
    {
        *contador = *contador+1;
        printf("%d ) ", *contador);
        printf("Mover disco del poste %c ", i);
        printf("al %c\n", j);
    }
    else
    {
        colocar(n-1,i,k,j,&*contador);
        *contador = *contador+1;
        printf("%d ) ", *contador);
        printf("Mover disco del poste %c ", i);
        printf("al %c\n", j);
        colocar(n-1,k,j,i,&*contador);
    }
    return;
}
