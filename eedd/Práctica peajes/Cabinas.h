/*
 *	MODULO: cabinas
 *	FICHERO: cabinas.h
 *	VERSION: 1.0.0
 *	HISTORICO:
 *	Creado por Álvaro Larraya Conejo el 08/05/20.
 *  DESCRIPCION: Este modulo exporta la funcionalidad necesaria para implementar una cabina de peaje.
 */
#ifndef ALC_CABINAS_H
#define ALC_CABINAS_H
#include "ColaDeEnteros.h"
#include "reloj.h"
#include "ruleta.h"
typedef struct Cabina {
	int nCoches;
    int maxCoches;
    int servidos;
    int totalEsperado;
    int proxServ;
    int minServ;
    int maxServ;
    ColaDeEnteros colaCoches;
} Cabina;
/*
 *  ACCION: iniciarCab
 *  ENTRADA: tmin y tmax enteros
 *  REQUISITOS: Ninguno
 *  SALIDA: inicia la cabina sin coches esperando
 */
void iniciarCab (Cabina *, int, int);
/*
 *  ACCION: encolarCoche
 *  ENTRADA: r Reloj
 *  REQUISITOS: la cabina debe estar inicializada
 *  SALIDA: Pone en el instante r un coche en espera en la cabina
 */
void encolarCoche (Cabina *, Reloj);
/*
 *  FUNCIÓN: cuantosCoches
 *  ENTRADA: cab Cabina
 *  REQUISITOS: la cabina  y el reloj deben estar inicializados
 *  SALIDA: Da el numero de coches esperando en la cabina
 */
int cuantosCoches (Cabina);
/*
 *  ACCION: servCabina
 *  ENTRADA: r Reloj
 *  REQUISITOS: la cabina  y el reloj deben estar inicializados
 *  SALIDA: Pone en el instante r un coche en espera en la cabina
 */
void servCabina (Cabina *, Reloj);
#endif
