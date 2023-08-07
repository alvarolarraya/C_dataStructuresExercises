//Programa: dientes_de_sierra
//Álvaro Larraya
//14 de octubre de 2019
//Este programa calcula la imagen de x en la función: f(x)=3/5*(x-10*k) para el intervalo [10k-5,10k+5)
#include <stdio.h>
int main()
{
    char res;
    float x,y;
    int k;
    printf("Programa: dientes_de_sierra\n");
    printf("Álvaro Larraya\n");
    printf("14 de octubre de 2019\n");
    printf("Este programa calcula la imagen de x en la función: f(x)=3/5*(x-10*k) para el intervalo [10k-5,10k+5)\n");
    do
    {
        printf("Por favor, introduzca un número entero para la variable x: \n");
        scanf(" %f", &x);
        k = 0;
        if (-5<=x)
        {
            while (x>=(10*k+5))
                k = k+1;
        }
        else
        {
            while ((10*k-5)>x)
                k = k-1;
        };
        y = ((3.0/5.0)*(x-10*k));
        printf("La imagen de x en f(x) = %f \n", y);
        printf("¿Desea continuar usando el programa?: s/n\n");
        scanf(" %c", &res);
    }while(res == 's' || res == 'S');
    return 0;
}
