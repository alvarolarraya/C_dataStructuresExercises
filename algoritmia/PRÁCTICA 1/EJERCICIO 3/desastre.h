/*
  FICHERO: desastre.h
  VERSION: 1.0.0
  HISTORICO:
  Creado por Álvaro Larraya Conejo el 10/07/20.
  
  Este modulo crea tipo desastre, da la opción de meter la fecha, número de victimas y consultar estos dos anteriores y el último gran accidente desde esa fecha.
*/
#ifndef ALC_DESASTRES_H
#define ALC_DESASTRES_H
#include <stdio.h>
typedef struct desastre
{
    int fecha;
    int victimas;
    int ultimoMasMuertos;
}desastre;
typedef int victimas;
typedef int fecha;
void meterFecha (fecha, desastre *);
void meterVictimas (victimas, desastre *);
int cuantasVictimas(desastre);
int cuandoFue(desastre);
int ultimoMayor(desastre);
#endif
