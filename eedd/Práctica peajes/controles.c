/*
 *	MODULO: controles
 *	FICHERO: controles.h
 *	VERSION: 1.0.0
 *	HISTORICO:
 *	Creado por Álvaro Larraya Conejo el 15/05/20.
 *  DESCRIPCION: Este modulo exporta la funcionalidad necesaria para implementar un control de autopista que se compone de un peaje e información sobre el tráfico.
 */
#include "controles.h"
void iniciarControl (Control *c)
{
    printf("Introduzca el tiempo medio (segundos) de llegada entre un coche y el siguiente: ");
    scanf("%d", &c->trafico.tMedio);
    c->trafico.tLlegada = distribucionExponencial(c->trafico.tMedio);
    iniciarPeaje(c->peaje);
}
void llegaCoche (Control *c, Reloj r)
{
    int n;
    if (instante(r) == c->trafico.tLlegada)
    {
        n = eligeCabina (c->peaje);
        guardaCola (c->peaje, n, r);
        c->trafico.tLlegada = instante(r)+distribucionExponencial(c->trafico.tMedio);
    }
}
void marchaCoche (Control *c, Reloj r)
{
    rondaCabinas(c->peaje, r);
}
