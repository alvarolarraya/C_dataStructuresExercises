/*
 *	MODULO: ruleta
 *	FICHERO: ruleta.h
 *	VERSION: 1.0.0
 *	HISTORICO:
 *	Creado por Álvaro Larraya Conejo el 29/04/20.
 *  DESCRIPCION: Este modulo exporta la funcionalidad necesaria para implementar una ruleta.
 */
#ifndef ALC_RULETA_H
#define ALC_RULETA_H
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
typedef float tabla[3];
/*
 *  ACCION: iniciarRuleta
 *  ENTRADA: Ninguna
 *  REQUISITOS: Ninguno
 *  MODIFICA: Inicia la generacion de numeros aleatorios
 */
void iniciarRuleta();
/*
 *  ACCION: distribucionExponencial
 *  ENTRADA: entero llamado media
 *  REQUISITOS: La ruleta debe haberse inicializado
 *  SALIDA: Devuelve la probabilidad de que salga un valor aleatorio en una distribución exponencial de media el parámetro de entrada
 */
int distribucionExponencial (int);
/*
 *  ACCION: distribucionLineal
 *  ENTRADA: enteros llamados max y min
 *  REQUISITOS: La ruleta debe haberse inicializado
 *  SALIDA: Devuelve la probabilidad de que salga un valor aleatorio en una distribución lineal acotada por min y max
 */
int distribucionLineal (int, int);
/*
 *  ACCION: eleccionCon3Probabilidades
 *  ENTRADA: enteros llamados maxp, minp, medp
 *  REQUISITOS: La ruleta debe haberse inicializado
 *  SALIDA: elige entre tres opciones con probabilidades dadas
 */
int eleccionCon3Probabilidades (float, float, float);
#endif
