#include "PilaDeCaracteres.h"
#include<string.h>

int main()
{
    int longitud,i,error;
    char frase[100];
    tipoPila p;
    error = 0;
    printf("Introduce la frase: ");
    fgets(frase, sizeof(frase), stdin);
    longitud = strlen(frase);
    for(i = 0; i<longitud;i++)
    {
        if(frase[i] == '{' ||frase[i] == '('||frase[i] == '[')
            apilar(&p,frase[i]);
        else if (frase[i] == '}' ||frase[i] == ')'||frase[i] == ']')
        {
            if (!esNulaPila(p))
            {
                if ((cima(p) == '{' && frase[i] != '}') || (cima(p) == '(' && frase[i] != ')') || (cima(p) == '[' && frase[i] != ']'))
                {
                    error = 1;
                    break;
                }
                else
                    desapilar(&p);
            }
            else
                error = 1;
        }
    }
    if (!esNulaPila(p))
        error = 1;
    if (error == 0)
        printf("Esta bien balanceada\n");
    else
        printf("No esta bien balanceada\n");
    return 0;
}
