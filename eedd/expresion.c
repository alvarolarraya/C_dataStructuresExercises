/*
 *	MODULO: expresion
 *	FICHERO: expresion.h
 *	VERSION: 1.0.0
 *	HISTORICO:
 *	Creado por Álvaro Larraya Conejo el 13/04/20.
 *  DESCRIPCION: Este modulo exporta la funcionalidad necesaria para implementar
 * 	una expresion.
 */
#include <stdio.h>
#include "expresion.h"
/*
 *  ACCION: error
 *  REQUISITOS: Ninguno
 *  SALIDA: Para la ejecución tras informar de un error
 */
void errorExpresion(char s[]);
/*
 *  ACCION: llena
 *	REQUISITOS:
 *  SALIDA: Devuelve verdadero si la expresion está llena
 */
bool llenaExpresion(Expresion e);
void errorExpresion(char s[])
{
    printf("\n\n\nERROR en el módulo expresion: %s \n", s);
	while (true)
		exit(-1);
}
bool llenaExpresion(Expresion e)
{
    return (e.fin > (TAMANIO_EXPRESION-1));
}
/*
 *  ACCION: expresionNula
 *  ENTRADA: Ninguna
 *  REQUISITOS: Que no haya sido inicializada antes
 *  SALIDA: e una expresion vacía
 */
void expresionNula(Expresion *e)
{
    e->inicio = 0;
    e->fin = 0;
}
/*
 *  ACCION: aniadeSimbolo
 *  ENTRADA: e una expresion y x un simbolo
 *  REQUISITOS: La expresion debe estar ya inicializada
 *  MODIFICA: La expresion contiene ahora además el simbolo x
 */
void aniadeSimbolo(Expresion *e, Simbolo x)
{
    int ocupados;
    if (llenaExpresion(*e))
    {
        for (ocupados = 1; ocupados < (TAMANIO_EXPRESION-e->inicio); ocupados = ocupados+1)
        {
            e->valores[ocupados] = e->valores[e->inicio];
            e->inicio = e->inicio+1;
        }
    }
    e->valores[e->fin] = x;
    e->fin = e->fin+1;
}
/*
 *  ACCION: eliminaSimbolo
 *  ENTRADA: e expresion
 *  REQUISITOS: Que la expresion no sea vacía
 *  MODIFICA: La expresion cuenta con un simbolo menos que ocupaba la posición inicio
 */
void eliminaSimbolo (Expresion *e)
{
    e->inicio = e->inicio+1;
}
/*
 *  ACCION: primerSimbolo
 *  ENTRADA: e expresion
 *  REQUISITOS: La expresion debe no ser vacía
 *  SALIDA: x el valor en la posición inicio
 */
void primerSimbolo(Expresion e, Simbolo *x)
{
    if (expresionVacia(e))
        errorExpresion("Consultando primero de una expresion vacía");
    *x = e.valores[e.inicio];
}
/*
 *  FUNCION: expresionVacia
 *  ENTRADA: e una expresion
 *  REQUISITOS: Ninguno
 *  SALIDA: booleano que se hace cierto si e es una expresion vacía
 */
bool expresionVacia(Expresion e)
{
    return (e.inicio == e.fin);
}
