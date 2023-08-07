/*
 *	MODULO: peajes
 *	FICHERO: peajes.h
 *	VERSION: 1.0.0
 *	HISTORICO:
 *	Creado por Álvaro Larraya Conejo el 08/05/20.
 *  DESCRIPCION: Este modulo exporta la funcionalidad necesaria para implementar el peaje de una cabina.
 */
#ifndef ALC_PEAJES_H
#define ALC_PEAJES_H
#define NCAB 5
#include "Cabinas.h"
typedef Cabina Peaje[NCAB];
typedef struct pareja{
	int can;
    int cab;
} pareja;
typedef pareja taux[NCAB];
#define PROB_MAX 0.6
#define PROB_MEDIA 0.3
#define PROB_MIN 0.1
/*
 *  ACCION: iniciarPeaje
 *  ENTRADA: p peaje
 *  REQUISITOS: Ninguno
 *  SALIDA: Inicia el peaje
 */
void iniciarPeaje (Peaje);
/*
 *  ACCION: guardaCola
 *  ENTRADA: p peaje, ncab entero, r Reloj
 *  REQUISITOS: el peaje debe haber sido inicializado
 *  SALIDA: Encola un nuevo coche en una cabina
 */
void guardaCola (Peaje , int, Reloj);
/*
 *  FUNCIÓN: eligeCabina
 *  ENTRADA: p peaje
 *  REQUISITOS: el peaje debe haber sido inicializado
 *  SALIDA: Elige cabina entre las tres menos ocupadas
 */
int eligeCabina (Peaje);
/*
 *  ACCION: rondaCabinas
 *  ENTRADA: p peaje, r Reloj
 *  REQUISITOS: el peaje debe haber sido inicializado
 *  SALIDA: Simula una ronda de servicio de las cabinas
 */
void rondaCabinas (Peaje , Reloj);
#endif
