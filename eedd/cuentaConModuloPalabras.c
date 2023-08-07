/*Programa: cuenta
 * Fichero: cuenta.c
 * Histórico:
 *  Creado por Álvaro Larraya el 25/3/2020.
 *  versión 1.0.0
 * Copyright © 2016 Álvaro Larraya. All rights reserved.
 */
#include <stdio.h>
#include "palabras.h"
/*
 * PROGRAMA PRINCIPAL
 * ENTRADA: f fichero de palabras
 * REQUISITOS: Debe haber mínimo un elemento en el fichero
 * SALIDA: el programa cuenta el número de veces que aparece la primera palabra
 */
int main()
{
    char quiereSalir;
    FILE * f;
    palabra p1,p;
    int contador;
    do
    {
        f = fopen("fichero.palabras", "r");
        contador = 0;
        leerPalabra(f,&p1);
        while (!feof(f))
        {
            leerPalabra(f,&p);
            if (sonPalabrasIguales(p1,p))
                contador = contador+1;
        }
        if (sonPalabrasIguales(p1,p))
                contador = contador+1;
        printf("La primera palabra se repite %d veces", contador);
        fclose(f);
        return 0;
        printf("¿Desea seguir usando el programa?: s/n ");
        scanf(" %c", &quiereSalir);
    }while (quiereSalir == 's' || quiereSalir == 'S');
}
