/*
 *	MODULO: expresion
 *	FICHERO: expresion.h
 *	VERSION: 1.0.0
 *	HISTORICO:
 *	Creado por Álvaro Larraya Conejo el 13/04/20.
 *  DESCRIPCION: Este modulo exporta la funcionalidad necesaria para implementar
 * 	una expresion.
 */
#ifndef ALC_EXPRESION_H
#define ALC_EXPRESION_H
#include "simbolos.h"
#include <stdlib.h>
#define TAMANIO_EXPRESION 100 //número de simbolos que contiene la expresion
typedef struct Expresion {
	Simbolo valores[TAMANIO_EXPRESION];
	int inicio,fin;
} Expresion;
/*
 *  ACCION: expresionNula
 *  ENTRADA: Ninguna
 *  REQUISITOS: Que no haya sido inicializada antes
 *  SALIDA: e una expresion vacía
 */
void expresionNula(Expresion *e);
/*
 *  ACCION: aniadeSimbolo
 *  ENTRADA: e una expresion y x un simbolo
 *  REQUISITOS: La expresion debe estar ya inicializada
 *  MODIFICA: La expresion contiene ahora además el simbolo x
 */
void aniadeSimbolo(Expresion *e, Simbolo x);
/*
 *  ACCION: eliminaSimbolo
 *  ENTRADA: e expresion
 *  REQUISITOS: Que la expresion no sea vacía
 *  MODIFICA: La expresion cuenta con un simbolo menos que ocupaba la posición inicio
 */
void eliminaSimbolo (Expresion *e);
/*
 *  ACCION: primerSimbolo
 *  ENTRADA: e expresion
 *  REQUISITOS: La expresion debe no ser vacía
 *  SALIDA: x el valor en la posición inicio
 */
void primerSimbolo(Expresion e, Simbolo *x);
/*
 *  FUNCION: expresionVacia
 *  ENTRADA: e una expresion
 *  REQUISITOS: Ninguno
 *  SALIDA: booleano que se hace cierto si e es una expresion vacía
 */
bool expresionVacia(Expresion e);
#endif
