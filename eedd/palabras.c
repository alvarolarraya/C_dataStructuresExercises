/**
 *	MODULO: palabras
 *	FICHERO: palabras.h
 *	VERSION: 1.0.0
 *	HISTORICO:
 *		Creado por Álvaro Larraya Conejo el 25/03/20.
 * DESCRIPCION: Implementación de las funciones declaradas en
 * 	palabras.h
 */
#include "palabras.h"
#include <stdio.h>
#define MAX 100
typedef char tabla [MAX];
void prepararPalabra (palabra *p)
{
    p->longitud = 0;
}
void agregarCaracter (palabra *p, char c)
{
    if (longitudPalabra(*p)< MAX)
    {
        p->longitud = p->longitud+1;
        p->letras [p->longitud] = c;
    }
}
void modificarCaracter (palabra *p, int i, char c)
{
    p->letras [i] = c;
}
char consultarCaracter (palabra p, int i)
{
    char c;
    c = p.letras [i];
    return c;
}
int longitudPalabra (palabra p)
{
    int longitud;
    longitud = p.longitud;
    return longitud;
}
boolean esPalabraVacia (palabra p)
{
    boolean b;
    b = (longitudPalabra(p) == 0);
    return b;
}
boolean sonPalabrasIguales (palabra p1, palabra p2)
{
    boolean b;
    int i;
    if (longitudPalabra(p1) == longitudPalabra(p2))
    {
        i = 1;
        while (i < longitudPalabra(p1) && consultarCaracter(p1,i) == consultarCaracter(p2,i))
            i = i+1;
        b = (consultarCaracter(p1,i) == consultarCaracter(p2,i));
    }
    else
        b = FALSE;
    return b;
}
/*
 * ACCION: saltarBlancos
 * ENTRADA: f, fichero de caracter
 * REQUISITOS: La parte derecha del fichero debe ser distinto de vacío
 * MODIFICA:  f, a la salida el elemento distinguido de f es el primer caracter no blanco de la parte derecha del fichero
 * SALIDA:  c, un caracter que coincide con el elemento distinguido de f
 */
void saltarBlancos(FILE *f, char *c);
void saltarBlancos(FILE *f, char *c)
{
    *c = fgetc(f);
    while (!feof(f) && (*c == ' '))
        *c = fgetc(f);
    return;
}
/*
 * ACCION: copiarLetras
 * ENTRADA: f:  fichero de caracter y un caracter
 * REQUISITOS: c coincide con el elemento distinguido de f;
 * MODIFICA:  f avanzando el elemento distinguido hasta el principio de la siguiente palabra
 * SALIDA:   p contiene la primera palabra de la parte derecha del fichero
 */
void copiarLetras(FILE *f, palabra *p);
void copiarLetras(FILE *f, palabra *p)
{
    char c;
    p->longitud = 0;
    while (!feof(f) && (c != ' '))
    {
        agregarCaracter(p,c);
        c = fgetc(f);
    }
    if (c != ' ')
    {
        agregarCaracter(p,c);
    }
}
/*
 * ACCION: leerPalabra
 * ENTRADA: f, fichero de caracter
 * REQUISITOS: El fichero no esta vacio y la parte derecha es distinta de epsilon
 * MODIFICA:  f avanzando el elemento distinguido hasta el principio de la siguiente palabra
 * SALIDA: p (entero) contiene la primera palabra de la parte derecha
 */
void leerPalabra(FILE *f, palabra *p);
void leerPalabra(FILE *f, palabra *p)
{
    char c;
    prepararPalabra(&*p);
    if (!feof(f))
    {
        saltarBlancos(f,&c);
        copiarLetras(f,&*p);
    }
}
