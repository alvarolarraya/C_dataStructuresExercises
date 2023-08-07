/*
 *	MODULO: peajes
 *	FICHERO: peajes.h
 *	VERSION: 1.0.0
 *	HISTORICO:
 *	Creado por Álvaro Larraya Conejo el 08/05/20.
 *  DESCRIPCION: Este modulo exporta la funcionalidad necesaria para implementar el peaje de una cabina.
 */
#include "peajes.h"
struct intervalo{
	int min;
    int max;
};
const struct intervalo tipoCobro [NCAB] = {
    {.min = 15, .max = 30},
    {.min = 15, .max = 30},
    {.min = 15, .max = 45},
    {.min = 15, .max = 45},
    {.min = 30, .max = 60}
};
void ordenar (taux t);
void ordenar (taux t)
{
    int x,i,j;
    i = 1;
    while (i != NCAB)
    {
        x = t[i].cab;
        j = i-1;
        while ((t[i].can <= t[j].can) && (j != 0))
        {
            t[j].cab = t[j].cab+1;
            j = j-1;
        }
        if (t[i].can >= t[j].can)
            t[j+1].cab = x;
        else
        {
            t[j].cab = t[j].cab+1;
            t[i].cab = j;
        }
        i = i+1;
    }
}
void guardaCola (Peaje p, int ncab, Reloj r)
{
    encolarCoche(&p[ncab],r);
}
void iniciarPeaje (Peaje p)
{
    int i;
    for (i = 0; i<NCAB; i++)
        iniciarCab(&p[i], tipoCobro[i].min, tipoCobro[i].max);
}
int eligeCabina (Peaje p)
{
    int x,i,n;
    taux t;
    for (i = 0; i<NCAB; i++)
    {
        t[i].can = cuantosCoches(p[i]);
        t[i].cab = i;
    }
    ordenar(t);
    x = eleccionCon3Probabilidades(PROB_MAX, PROB_MEDIA, PROB_MIN);
    n = t[x].cab;
    return n;
}
void rondaCabinas (Peaje p, Reloj r)
{
    int i;
    for (i = 0; i<NCAB; i++)
        servCabina(&p[i], r);
}
