#include "colaDobleCaracteres.h"
    
void nuevaColaDoble(tipoColaDoble *cola)
{
    cola->ini = NULL;
    cola->fin = NULL;
}

void encolarPrimero(tipoColaDoble *cola, tipoElementoColaDoble elemento)
{
    celdaColaDoble* nuevaCelda;
    if((nuevaCelda = malloc(sizeof(celdaColaDoble*))) == NULL)
            perror("no hay suficiente memoria para reservar en encolarPrimero");
    nuevaCelda->elem = elemento;
    nuevaCelda->ant = NULL;
    if(cola->ini == NULL && cola->fin == NULL)
    {
        cola->ini = nuevaCelda;
        cola->fin = nuevaCelda;
        nuevaCelda->sig = NULL;
    }
    else
    {
        cola->ini->ant = nuevaCelda;
        nuevaCelda->sig = cola->ini;
        cola->ini = nuevaCelda;
    }
}

void encolarUltimo(tipoColaDoble *cola, tipoElementoColaDoble elemento)
{
    celdaColaDoble* nuevaCelda;
    if((nuevaCelda = malloc(sizeof(celdaColaDoble*))) == NULL)
            perror("no hay suficiente memoria para reservar en encolarPrimero");
    nuevaCelda->elem = elemento;
    nuevaCelda->sig = NULL;
    if(cola->ini == NULL && cola->fin == NULL)
    {
        cola->ini = nuevaCelda;
        cola->fin = nuevaCelda;
        nuevaCelda->ant = NULL;
    }
    else
    {
        cola->fin->sig = nuevaCelda;
        nuevaCelda->ant = cola->fin;
        cola->fin = nuevaCelda;
    }
}

void desencolarPrimero(tipoColaDoble * cola)
{
    if(cola->ini == NULL && cola->fin == NULL)
    {
        perror("no se puede borrar de una cola vacía");   
    }
    celdaColaDoble* aux;
    if((aux = malloc(sizeof(celdaColaDoble*))) == NULL)
            perror("no hay suficiente memoria para reservar en encolarPrimero");
    aux = cola->ini;
    if(cola->ini->sig == NULL)
    {
        cola->fin = NULL;
        cola->ini = NULL;
    }
    else
    {
        cola->ini = cola->ini->sig;
        cola->ini->ant = NULL;
    }
    free(aux);
}

void desencolarUltimo(tipoColaDoble * cola)
{
    if(cola->ini == NULL && cola->fin == NULL)
    {
        perror("no se puede borrar de una cola vacía");   
    }
    celdaColaDoble* aux;
    if((aux = malloc(sizeof(celdaColaDoble*))) == NULL)
            perror("no hay suficiente memoria para reservar en encolarPrimero");
    aux = cola->fin;
    if(cola->fin->ant == NULL)
    {
        cola->fin = NULL;
        cola->ini = NULL;
    }
    else
    {
        cola->fin = cola->fin->ant;
        cola->fin->sig = NULL;
    }
    free(aux);
}

tipoElementoColaDoble elemPrimero(tipoColaDoble cola)
{
    return cola.ini->elem;   
}

tipoElementoColaDoble elemUltimo(tipoColaDoble cola)
{
    return cola.fin->elem;
}

bool esNulaColaDoble(tipoColaDoble cola)
{
    return (cola.ini == NULL && cola.fin == NULL);
}