/*
 *	MODULO: ColaDeEnteros
 *	FICHERO: ColaDeEnteros.h
 *	VERSION: 1.0.0
 *	HISTORICO:
 *	Creado por Álvaro Larraya Conejo el 30/04/20.
 *  DESCRIPCION: Este modulo exporta la funcionalidad necesaria para implementar una cola de enteros.
 */
#include "ColaDeEnteros.h"
void errorColaDeEnteros(char s[]);
void errorColaDeEnteros (char s[])
{
	printf("\n\n\nERROR en el módulo cola de enteros: %s \n", s);
	while (true)
		exit(-1);
}
void nuevaColaDeEnteros (ColaDeEnteros *c)
{
    c->i = NULL;
    c->f = NULL;
}
void pideTurnoColaDeEnteros (ColaDeEnteros *c, int x)
{
    CeldaDeInt *q;
    if ((q = malloc(sizeof(CeldaDeInt))) == NULL)
        errorColaDeEnteros("no hay memoria para pideTurno");
    q->e = x;
    q->s = NULL;
    if (c->f == NULL)
        c->i = q;
    else
        c->f->s = q;
    c->f = q;
}
bool esNulaColaDeEnteros (ColaDeEnteros c)
{
    return (c.i == NULL);
}
void avanceColaDeEnteros(ColaDeEnteros *c)
{
    CeldaDeInt *q;
    if (esNulaColaDeEnteros(*c))
        errorColaDeEnteros("avanzando en cola nula");
    q = c->i;
    c->i = c->i->s;
    if (c->i == NULL)
        c->f = NULL;
    free(q);
}
void primeroColaDeEnteros (ColaDeEnteros c, int *x)
{
    if (esNulaColaDeEnteros(c))
        errorColaDeEnteros("primero en cola nula");
    *x = c.i->e;
}
