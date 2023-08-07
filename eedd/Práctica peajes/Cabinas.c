/*
 *	MODULO: cabinas
 *	FICHERO: cabinas.h
 *	VERSION: 1.0.0
 *	HISTORICO:
 *	Creado por Álvaro Larraya Conejo el 08/05/20.
 *  DESCRIPCION: Este modulo exporta la funcionalidad necesaria para implementar una cabina de peaje.
 */
#include "Cabinas.h"
void iniciarCab (Cabina *cab, int tmin, int tmax)
{
    cab->nCoches = 0;
    cab->maxCoches = 0;
    cab->servidos = 0;
    cab->totalEsperado = 0;
    cab->proxServ = 0;
    cab->minServ = tmin;
    cab->maxServ = tmax;
    nuevaColaDeEnteros(&cab->colaCoches);
}
void contarCoche (Cabina *, Reloj);
void contarCoche (Cabina *cab, Reloj r)
{
    if (cab->nCoches == 0)
        cab->proxServ = instante(r)+distribucionLineal(cab->minServ, cab->maxServ);
    cab->nCoches = cab->nCoches+1;
    if (cab->nCoches > cab->maxCoches)
        cab->maxCoches = cab->nCoches;
}
void encolarCoche (Cabina *cab, Reloj r)
{
    contarCoche(cab, r);
    pideTurnoColaDeEnteros(&cab->colaCoches, instante(r));
}
int cuantosCoches (Cabina cab)
{
    int n;
    n = cab.nCoches;
    return n;
}
void servCabina (Cabina *cab, Reloj r)
{
    int x;
    if (cab->proxServ == instante(r))
    {
        cab->servidos = cab->servidos+1;
        primeroColaDeEnteros(cab->colaCoches, &x);
        avanceColaDeEnteros(&cab->colaCoches);
        cab->totalEsperado = cab->totalEsperado + (instante(r) - x);
        cab->nCoches = cab->nCoches - 1;
        if (cab->nCoches == 0)
            cab->proxServ = 0;
        else
            cab->proxServ = instante(r)+distribucionLineal(cab->minServ,cab->maxServ);
    }
}
