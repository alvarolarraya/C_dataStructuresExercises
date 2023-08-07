/*
  FICHERO: desastre.h
  VERSION: 1.0.0
  HISTORICO:
  Creado por Álvaro Larraya Conejo el 10/07/20.
  
  Este modulo crea tipo desastre, da la opción de meter la fecha, número de victimas y consultar estos dos anteriores y el último gran accidente desde esa fecha.
*/

#include "desastre.h"
void meterFecha (fecha f, desastre *d)
{
    d->fecha = f;
    return;
}
void meterVictimas (victimas v, desastre *d)
{
    d->victimas = v;
    return;
}
int cuantasVictimas(desastre d)
{
    return d.victimas;
}
int cuandoFue(desastre d)
{
    return d.fecha;
}
int ultimoMayor(desastre d)
{
    return (d.ultimoMasMuertos);
}
