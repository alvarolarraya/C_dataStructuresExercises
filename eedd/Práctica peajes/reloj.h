/*
 *	MODULO: reloj
 *	FICHERO: reloj.h
 *	VERSION: 1.0.0
 *	HISTORICO:
 *	Creado por Álvaro Larraya Conejo el 29/04/20.
 *  DESCRIPCION: Este modulo exporta la funcionalidad necesaria para implementar un reloj.
 */
#ifndef ALC_RELOJ_H
#define ALC_RELOJ_H
#include <stdlib.h>
#include <stdio.h>
#define TRUE 1
typedef int Reloj;
/*
 *  ACCION: aCero
 *  ENTRADA: Ninguna
 *  REQUISITOS: Ninguno
 *  SALIDA: Pone a cero la cuenta del reloj r
 */
void aCero (Reloj *);
/*
 *  ACCION: tic
 *  ENTRADA: r Reloj
 *  REQUISITOS: El reloj debe estar ya inicializado
 *  MODIFICA: Incrementa en uno la cuenta del reloj r
 */
void tic (Reloj *);
/*
 *  FUNCIÓN: instante
 *  ENTRADA: r Reloj
 *  REQUISITOS: El reloj debe estar ya inicializado
 *  SALIDA: Devuelve el valor en segundos de la cuenta del reloj r
 */
int instante (Reloj );
#endif
