#include "colaDobleCaracteres.h"
#include <string.h>

void primeraParteCodificacion(tipoColaDoble *cola, celdaColaDoble* aux);
bool esVocal(char letra);
void intercambiar(char* letra1, char* letra2);

int main()
{
    tipoColaDoble cola;
    char* frase;
    celdaColaDoble* aux;
    int i = 0;
    char letra;
    //inicializo la cola doble
    nuevaColaDoble(&cola);
    //reservo memoria para la frase
    if ((frase = malloc(sizeof(char*))) == NULL)
        perror("no se ha podido reservar memoria a la frase correctamente");
    //pido al usuario la frase
    printf("¿Cuál es el mensaje a codificar?: ");
    fgets(frase,100,stdin);
    //meto la frase en la cola doble
    while(frase[i] != '\n')
    {
        encolarUltimo(&cola,frase[i]);
        i++;
    }
    //reservo memoria para el auxiliar
    if((aux = malloc(sizeof(celdaColaDoble*))) == NULL)
        perror("no hay espacio suficiente para reservar aux");
    //inicializo el auxiliar apuntandolo al principio de la cola
    aux = cola.ini;
    //realizo la primera parte de la codificacion
    printf("Tras la primera codificación el mensaje es: ");
    primeraParteCodificacion(&cola,aux);
    printf("\n");
    //hago la segunda parte de la codificacion
    i = 0;
    while(!esNulaColaDoble(cola))
    {
        letra = elemPrimero(cola);
        frase[i] = letra;
        desencolarPrimero(&cola);
        i++;
        if(!esNulaColaDoble(cola))
        {
            letra = elemUltimo(cola);
            frase[i] = letra;
            desencolarUltimo(&cola);
            i++;
        }
    }
    printf("Asi es como queda el mensaje tras la segunda codificacion: %s",frase);
    //hago la primera parte de la decodificacion
    i = 0;
    int tamanioCadena;
    tamanioCadena = strlen(frase);
    //los pares los encolo en el orden en el que estan
    while(i < (tamanioCadena-1))
    {
        letra = frase[i];
        encolarUltimo(&cola,letra);
        i = i+2;
    }
    i = tamanioCadena-2;
    //los impares al reves
    if(i%2 == 0)
        i = i-1;
    while(i > 0)
    {
        letra = frase[i];
        encolarUltimo(&cola,letra);
        i = i-2;
    }
    aux = cola.ini;
    printf("Este es el mensaje tras la primera decodificacion: ");
    while(aux != NULL)
    {
        printf("%c", aux->elem);
        aux = aux->sig;
    }
    printf("\n");
    //hago la segunda decodificacion
    aux = cola.ini;
    printf("Este es el mensaje tras la segunda decodificacion: ");
    primeraParteCodificacion(&cola,aux);
    printf("\n");
}

void primeraParteCodificacion(tipoColaDoble *cola, celdaColaDoble* aux)
{
    while(aux != NULL)
    {
        //si el anterior no es nulo y ni el aux, ni el anterior son vocales
        //los intercambio
        if(aux->ant != NULL)
        {
            if(!esVocal(aux->elem) && !esVocal(aux->ant->elem))
                intercambiar(&(aux->elem),&(aux->ant->elem));
            printf("%c", aux->ant->elem);
        }
        aux = aux->sig;
    }
    printf("%c", elemUltimo(*cola));
}

bool esVocal(char letra)
{
    return(letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u' || letra == 'A' || letra == 'E' || letra == 'I' || letra == 'O' || letra == 'U');
}

void intercambiar(char* letra1, char* letra2)
{
    char aux;
    aux = *letra1;
    *letra1 = *letra2;
    *letra2 = aux;
}
