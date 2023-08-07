/*
 *	MODULO: ColaDeEnteros
 *	FICHERO: ColaDeEnteros.h
 *	VERSION: 1.0.0
 *	HISTORICO:
 *	Creado por Álvaro Larraya Conejo el 30/04/20.
 *  DESCRIPCION: Este modulo exporta la funcionalidad necesaria para implementar una cola de enteros.
 */
#ifndef ALC_COLADEENTEROS_H
#define ALC_COLADEENTEROS_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct CeldaDeInt {
	int e;
    struct CeldaDeInt *s;
} CeldaDeInt;
typedef struct  ColaDeEnteros{
	CeldaDeInt *i,*f;
} ColaDeEnteros;
/*
 *  ACCION: nuevaColaDeEnteros
 *  ENTRADA: Ninguna
 *  REQUISITOS: Ninguno
 *  SALIDA: inicializa la cola c
 */
void nuevaColaDeEnteros (ColaDeEnteros *);
/*
 *  ACCION: pideTurnoColaDeEnteros
 *  ENTRADA: c una cola de enteros y e un entero
 *  REQUISITOS: Ninguno
 *  MODIFICA: Almacena e como ultimo elemento de c
 */
void pideTurnoColaDeEnteros (ColaDeEnteros *, int);
/*
 *  ACCION: avanceColaDeEnteros
 *  ENTRADA: c una cola de enteros
 *  REQUISITOS: La cola no esta vacia
 *  MODIFICA: Elimina el elemento mas antiguo de la cola
 */
void avanceColaDeEnteros (ColaDeEnteros *);
/*
 *  ACCION: primeroColaDeEnteros
 *  ENTRADA: c una cola de enteros
 *  REQUISITOS: La cola no esta vacia
 *  SALIDA: Copia en e elemento mas antiguo de la cola
 */
void primeroColaDeEnteros (ColaDeEnteros, int *);
/*
 *  ACCION: esNulaColaDeEnteros
 *  ENTRADA: c una cola de enteros
 *  REQUISITOS: Ninguno
 *  SALIDA: Indica si c tiene elementos
 */
bool esNulaColaDeEnteros (ColaDeEnteros);
#endif
