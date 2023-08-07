#include <stdio.h>
int main()
{
    char   x, quiereSalir;
    FILE *f;
    do
    {
        f = fopen("fichero.palabras", "w");
        scanf(" %c", &x);
        while (x != '.')
        {
            fputs(&x,f);
            scanf(" %c", &x);
        }
        fclose(f);
        printf("¿Quiere volver a ejecutar el programa?: s/n ");
        scanf(" %c", &quiereSalir);  
    }while(quiereSalir == 's' || quiereSalir == 'S');
    return 0;
}
