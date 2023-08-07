/*
 *	MODULO: ColaDeDesastres
 *	FICHERO: ColaDeDesastres.h
 *	VERSION: 1.0.0
 *	HISTORICO:
 *	Creado por Álvaro Larraya Conejo el 30/04/20.
 *  DESCRIPCION: Este modulo exporta la funcionalidad necesaria para implementar una cola de desastres.
 */
#include "ColaDeDesastres.h"
void errorColaDeDesastres(char s[]);
void errorColaDeDesastres (char s[])
{
	printf("\n\n\nERROR en el módulo cola de Desastres: %s \n", s);
	while (true)
		exit(-1);
}
void nuevaColaDeDesastres (ColaDeDesastres *c)
{
    c->i = NULL;
    c->f = NULL;
}
void pideTurnoColaDeDesastres (ColaDeDesastres *c, desastre d)
{
    CeldaDeDesastres *q;
    if ((q = malloc(sizeof(CeldaDeDesastres))) == NULL)
        errorColaDeDesastres("no hay memoria para pideTurno");
    q->d = d;
    q->s = NULL;
    if (c->f == NULL)
        c->i = q;
    else
        c->f->s = q;
    c->f = q;
}
bool esNulaColaDeDesastres (ColaDeDesastres c)
{
    return (c.i == NULL);
}
void avanceColaDeDesastres(ColaDeDesastres *c)
{
    CeldaDeDesastres *q;
    if (esNulaColaDeDesastres(*c))
        errorColaDeDesastres("avanzando en cola nula");
    q = c->i;
    c->i = c->i->s;
    if (c->i == NULL)
        c->f = NULL;
    free(q);
}
void primeroColaDeDesastres (ColaDeDesastres c, desastre *d)
{
    if (esNulaColaDeDesastres(c))
        errorColaDeDesastres("primero en cola nula");
    *d = c.i->d;
}
