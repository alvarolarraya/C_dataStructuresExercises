/*
 *	MODULO: controles
 *	FICHERO: controles.h
 *	VERSION: 1.0.0
 *	HISTORICO:
 *	Creado por Álvaro Larraya Conejo el 15/05/20.
 *  DESCRIPCION: Este modulo exporta la funcionalidad necesaria para implementar un control de autopista que se compone de un peaje e información sobre el tráfico.
 */
#ifndef ALC_CONTROLES_H
#define ALC_CONTROLES_H
#include "peajes.h"
typedef struct Frecuencia{
	int tLlegada;
    int tMedio;
} Frecuencia;
typedef struct Control{
	Peaje peaje;
    Frecuencia trafico;
} Control;
/*
 *  ACCION: iniciarControl
 *  MODIFICA: Inicia el control
 */
void iniciarControl (Control *);
/*
 *  ACCION: llegaCoche
 *  ENTRADA: r Reloj
 *  MODIFICA: Simula la llegada de un coche al control
 */
void llegaCoche (Control *, Reloj);
/*
 *  ACCION: marchaCoche
 *  ENTRADA: r Reloj
 *  MODIFICA: Simula la marcha de un coche del control
 */
void marchaCoche (Control *, Reloj);
#endif
