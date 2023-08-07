/*
 *	MODULO: reloj
 *	FICHERO: reloj.h
 *	VERSION: 1.0.0
 *	HISTORICO:
 *	Creado por Álvaro Larraya Conejo el 29/04/20.
 *  DESCRIPCION: Este modulo exporta la funcionalidad necesaria para implementar un reloj.
 */
#include "reloj.h"
void aCero (Reloj *r)
{
    *r = 0;
}
void tic (Reloj *r)
{
    *r = *r+1;
}
int instante (Reloj r)
{
    int i;
    i = r;
    return i;
}
