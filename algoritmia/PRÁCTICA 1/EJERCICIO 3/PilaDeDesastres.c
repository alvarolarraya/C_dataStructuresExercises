#include "PilaDeDesastres.h"

void errorPilaDeDesastres (char s[])
{
    printf("\n\n\nERROR en el módulo pila de Desastres: %s \n", s);
	while (true)
		exit(-1);
}
void nuevaPila(PilaDeDesastres *p)
{
    *p = NULL;
    return;
}

void apilar(PilaDeDesastres *p, desastre d)
{
    celdaPila* q;
    if ((q = malloc(sizeof(PilaDeDesastres))) == NULL)
        errorPilaDeDesastres("no hay memoria para apilar");
    q->d = d;
    q->sig = *p;
    *p = q;
    return;
}


bool esNulaPila(PilaDeDesastres p)
{
    return(p == NULL);
}


void desapilar(PilaDeDesastres *p)
{
    celdaPila* q;
    if (esNulaPila(*p))
        errorPilaDeDesastres("desapilando en pila nula\n");
    q = *p;
    *p = (*p)->sig;
    free(q);
    return;
}

desastre cima(PilaDeDesastres p)
{
    if (esNulaPila(p))
        errorPilaDeDesastres("Cima a pila nula\n");
    return p->d;
}
