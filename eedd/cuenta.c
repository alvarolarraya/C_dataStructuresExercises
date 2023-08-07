/*Programa: cuenta
 * Fichero: cuenta.c
 * Histórico:
 *  Creado por Álvaro Larraya el 4/3/2020.
 *  versión 1.0.0
 * Copyright © 2016 Álvaro Larraya. All rights reserved.
 */
#include <stdio.h>
#define N 1
typedef enum {FALSE = 0, TRUE=1} boolean;
typedef char tabla[N];
typedef struct palabra {
    tabla letras;
    int Long;
} palabra;
/*
 * ACCION: saltarBlancos
 * ENTRADA: f, fichero de caracter
 * REQUISITOS: La parte derecha del fichero debe ser distinto de vacío
 * MODIFICA:  f, a la salida el elemento distinguido de f es el primer caracter no blanco de la parte derecha del fichero
 * SALIDA:  c, un caracter que coincide con el elemento distinguido de f
 */
void saltarBlancos(FILE *f, char *c);
/*
 * ACCION: leerPalabra
 * ENTRADA: f, fichero de caracter
 * REQUISITOS: El fichero no esta vacio y la parte derecha es distinta de epsilon
 * MODIFICA:  f avanzando el elemento distinguido hasta el principio de la siguiente palabra
 * SALIDA: p (entero) contiene la primera palabra de la parte derecha
 */
void leerPalabra(FILE *f, palabra *p);
/*
 * ACCION: copiarLetras
 * ENTRADA: f:  fichero de caracter y un caracter
 * REQUISITOS: c coincide con el elemento distinguido de f;
 * MODIFICA:  f avanzando el elemento distinguido hasta el principio de la siguiente palabra
 * SALIDA:   p contiene la primera palabra de la parte derecha del fichero
 */
void copiarLetras(FILE *f, palabra *p);
/*
 * FUNCION: sonPalabrasIguales
 * ENTRADA: p1=P y p2=Q, dos palabras
 * REQUISITOS: p1 y p2 est ́an inicializadas
 * SALIDA:  el booleano b ser ́a verdadero si y s ́olo si P=Q
 */
boolean  sonPalabrasIguales(palabra p1, palabra p2);
/*
 * PROGRAMA PRINCIPAL
 * ENTRADA: f fichero de palabras
 * REQUISITOS: Debe haber mínimo un elemento en el fichero
 * SALIDA: el programa cuenta el número de veces que aparece la primera palabra
 */
int main()
{
    FILE * f;
    char quiereSalir;
    palabra p, primeraPalabra;
    int repeticionesPrimera;
    printf("\tPrograma cuenta\n");
    printf("\tCreado por Álvaro Larraya");
    printf("\tversion 1.0 (04/03/20)\n\n");
    printf("el programa cuenta el número  ");
    printf("de veces que aparece la primera palabra\n");
    do
    {
        f = fopen("fichero.palabras", "r");
        repeticionesPrimera = 0;
        leerPalabra(f,&p);
        primeraPalabra = p;
        leerPalabra(f,&p);
        while(!feof(f))
        {
            if (sonPalabrasIguales(p, primeraPalabra))
                repeticionesPrimera = repeticionesPrimera +1;
            leerPalabra(f,&p);
        }
        if (sonPalabrasIguales(p, primeraPalabra))
            repeticionesPrimera = repeticionesPrimera +1;
        fclose(f);
        printf("La primera palabra se repite %d", repeticionesPrimera);
        printf(" veces.\n");
        printf("¿Quiere volver a ejecutar el programa?: s/n ");
        scanf(" %c", &quiereSalir);   
    }while(quiereSalir == 's' || quiereSalir == 'S');
}
void saltarBlancos(FILE *f, char *c)
{
    *c = fgetc(f);
    while (!feof(f) && (*c == ' '))
        *c = fgetc(f);
    return;
}
void leerPalabra(FILE *f, palabra *p)
{
    char c;
    saltarBlancos(f,&c);
    copiarLetras(f,&*p);
    return;
}
void copiarLetras(FILE *f, palabra *p)
{
    char c;
    p->Long = 0;
    while (!feof(f) && (c != ' '))
    {
        p->Long = p->Long+1;
        p->letras[p->Long] = c;
        c = fgetc(f);
    }
    if (c != ' ')
    {
        p->Long = p->Long+1;
        p->letras[p->Long] = c;
    }
    return;
}
boolean  sonPalabrasIguales(palabra p1, palabra p2)
{
    int i;
    boolean b;
    if (p1.Long == p2.Long)
    {
        i = 1;
        while ((i < p1.Long) && (p1.letras[i] == p2.letras[i]))
            i = i+1;
        b = (p1.letras[i] == p2.letras[i]);
    }
    else
        b = FALSE;
    return b;
}
