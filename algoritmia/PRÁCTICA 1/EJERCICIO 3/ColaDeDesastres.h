/*
 *	MODULO: ColaDeDesastres
 *	FICHERO: ColaDeDesastres.h
 *	VERSION: 1.0.0
 *	HISTORICO:
 *	Creado por Álvaro Larraya Conejo el 30/04/20.
 *  DESCRIPCION: Este modulo exporta la funcionalidad necesaria para implementar una cola de desastres.
 */
#ifndef ALC_COLADEDESASTRES_H
#define ALC_COLADEDESASTRES_H
#include <stdlib.h>
#include <stdbool.h>
#include "desastre.h"
typedef struct CeldaDeDesastres {
	desastre d;
    struct CeldaDeDesastres *s;
} CeldaDeDesastres;
typedef struct  ColaDeDesastres{
	CeldaDeDesastres *i,*f;
} ColaDeDesastres;
/*
 *  ACCION: nuevaColaDeDesastres
 *  ENTRADA: Ninguna
 *  REQUISITOS: Ninguno
 *  SALIDA: inicializa la cola c
 */
void nuevaColaDeDesastres (ColaDeDesastres *);
/*
 *  ACCION: pideTurnoColaDeDesastres
 *  ENTRADA: c una cola de desastres y d como desastre
 *  REQUISITOS: Ninguno
 *  MODIFICA: Almacena d como ultimo elemento de c
 */
void pideTurnoColaDeDesastres (ColaDeDesastres *, desastre);
/*
 *  ACCION: avanceColaDeDesastres
 *  ENTRADA: c una cola de desastres
 *  REQUISITOS: La cola no esta vacia
 *  MODIFICA: Elimina el elemento mas antiguo de la cola
 */
void avanceColaDeDesastres (ColaDeDesastres *);
/*
 *  ACCION: primeroColaDeDesastres
 *  ENTRADA: c una cola de desastres
 *  REQUISITOS: La cola no esta vacia
 *  SALIDA: Copia en d elemento mas antiguo de la cola
 */
void primeroColaDeDesastres (ColaDeDesastres, desastre *);
/*
 *  ACCION: esNulaColaDeDesastres
 *  ENTRADA: c una cola de desastres
 *  REQUISITOS: Ninguno
 *  SALIDA: Indica si c tiene elementos
 */
bool esNulaColaDeDesastres (ColaDeDesastres);
#endif
