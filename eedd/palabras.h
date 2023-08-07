/*
 *	MODULO: palabras
 *	FICHERO: palabras.h
 *	VERSION: 1.0.0
 *	HISTORICO:
 *		Creado por Álvaro Larraya Conejo el 25/03/20.
 * DESCRIPCION: Este módulo permite trabajar con el tipo palabras, pudiendo crearlas, leerlas, saber su longitud, modificarlas y verificar si son o no palabras vacías o iguales, además de consultar el caracter en la posición i-ésima de una palabra.
 */
#ifndef PALABRA
#define PALABRA
#include <stdio.h>
#define MAX 100
typedef enum {FALSE = 0, TRUE = 1}boolean;
typedef char tabla [MAX];
typedef struct palabra {
	tabla letras;
	int longitud;
} palabra;
/*
 *  FUNCION: prepararPalabra 
 *	ENTRADA: 
 *  REQUISITOS: 
 *  SALIDA: p, una palabra inicializada a 0 letras;
 */
void prepararPalabra (palabra *p);
/*
 *  FUNCION: agregarCaracter
 *	ENTRADA: p, una palabra y c un caracter
 *  REQUISITOS: 
 *  MODIFICA: p, incorpora c como ultimo caracter de p;
 */
void agregarCaracter (palabra *p, char c);
/*
 *  FUNCION: modificarCaracter
 *	ENTRADA: p, una palabra, el entero i y c un caracter
 *  REQUISITOS: i es menor o igual que la longitud de p
 *  MODIFICA: Cambia por c el caracter i-esimo de p;
 */
void modificarCaracter (palabra *p, int i, char c);
/*
 *  FUNCION: consultarCaracter
 *  ENTRADA: p, una palabra y el entero i
 *  REQUISITOS: i es menor o igual que la longitud de p 
 *  SALIDA: Devuelve el caracter i-esimo de p;
 */
char consultarCaracter (palabra p, int i);
/*
 *  FUNCION:longitudPalabra 
 *  ENTRADA: p, una palabra
 *  REQUISITOS: 
 *  SALIDA: long, la longitud de p;
 */
int longitudPalabra (palabra p);
/*
 *  FUNCION: esPalabraVacia
 *  ENTRADA: p, una palabra;
 *  REQUISITOS: 
 *  SALIDA: el booleano b es verdadero si y solo si p no tiene letras
 */
boolean esPalabraVacia (palabra p);
/*
 *  FUNCION: sonPalabrasIguales
 *  ENTRADA: p1 y p2, dos palabras
 *  REQUISITOS: 
 *  SALIDA: el booleano b es verdadero si y solo si p1 y p2 son iguales;
 */
boolean sonPalabrasIguales (palabra p1, palabra p2);
/*
 *  FUNCION: leerPalabra
 *	ENTRADA: fichero de caracter
 *  REQUISITOS: El fichero no esta vacio y pd(f) es distinta de fdf
 *  MODIFICA: f avanzando el elemento distinguido hasta el principio de la siguiente palabra
 *  SALIDA: p (entero) contiene la primera palabra de pd(f);
 */
void leerPalabra (FILE *f, palabra *p);
#endif
