/*
 *	MODULO: ruleta
 *	FICHERO: ruleta.h
 *	VERSION: 1.0.0
 *	HISTORICO:
 *	Creado por Álvaro Larraya Conejo el 29/04/20.
 *  DESCRIPCION: Este modulo exporta la funcionalidad necesaria para implementar una ruleta.
 */
#include "ruleta.h"
void iniciarRuleta()
{
    srand(time(NULL));
}
int distribucionExponencial (int media)
{
    float x;
    int t;
    x = rand();
    x = x/RAND_MAX;
    t = (-log(1-x)*media);
    while (t == 0)
    {
        x = rand();
        x = x/RAND_MAX;
        t = (int)-log(1-x)*media;
    }
    return t;
}
int distribucionLineal (int min, int max)
{
    float x;
    int t;
    x = rand()/RAND_MAX;
    t = (int)((max-min)*x)+min;
    return t;
}
int eleccionCon3Probabilidades (float maxp, float medp, float minp)
{
    int n;
    float x;
    tabla elec;
    elec[0] = maxp;
    elec[1] = medp+maxp;
    elec[2] = 1;
    x = rand();
    x = x/RAND_MAX;
    n = 0;
    while ((elec[n]<x) && (n<2))
        n = n+1;
    return n;
}
