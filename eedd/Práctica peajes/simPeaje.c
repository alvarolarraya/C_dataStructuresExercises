/*Programa: simPeaje
 * Fichero: simPeaje.c
 * Histórico:
 *  Creado por Álvaro Larraya el 16/05/2020.
 *  versión 1.0.0
 * Copyright © 2016 Álvaro Larraya. All rights reserved.
 */
#define TSIM 10800
#include "controles.h"
/*
 *  ACCION: iniciarSimulacion
 *  ENTRADA: c Control
 *  REQUISITOS: Ninguno
 *  MODIFICA: inicia la ruleta y el control
 */
void iniciarSimulacion (Control *);
/*
 *  ACCION: siguienteIteracion
 *  ENTRADA: c Control y r Reloj
 *  REQUISITOS: Ninguno
 *  MODIFICA: simula el servicio al siguiente coche
 */
void siguienteIteracion (Control *, Reloj);
/*
 *  ACCION: mostrarResultados
 *  ENTRADA: c Control
 *  REQUISITOS: el control de entrada debe haber sido inicializado y instante (r) debe ser = TSIM
 *  SALIDA: muestra el tiempo medio (en segundos) de espera, la longitud (número de coches) máxima de la cola en cada una de las cabinas, el tiempo medio de espera en el peaje y el número total de coches servidos.
 */
void mostrarResultados (Control c);
/*
 * PROGRAMA PRINCIPAL
 * ENTRADA: Ninguno
 * REQUISITOS: Ninguno
 * SALIDA: El programa simula el funcionamiento de un peaje de autopista y muestra los resultados de la simulación del peaje
 */
int main()
{
    Reloj r;
    Control c;
    char quiereContinuar;
    printf("\tPrograma simPeaje\n");
    printf("\tCreado por Álvaro Larraya");
    printf("\tversion 1.0 (19/05/20)\n\n");
    printf("El programa simula el funcionamiento");
    printf(" de un peaje durante 3 horas y devuelve");
    printf(" el máximo número de coches que han estado");
    printf(" esperando en cada cabina, el tiempo medio");
    printf(" de espera (en segundos), por cabina y en el");
    printf(" peaje en total (además de en segundos ");
    printf("mostrado en minutos), el número total de coches atendidos\n");
    do
    {
        aCero (&r);
        iniciarSimulacion (&c);
        while (instante (r) != TSIM)
        {
            tic (&r);
            siguienteIteracion (&c, r);
        }
        mostrarResultados (c);
        printf("¿Desea continuar usando el programa?: s/n ");
        scanf(" %c", &quiereContinuar);
    } while (quiereContinuar == 's' || quiereContinuar == 'S');
    return 0;
}
void iniciarSimulacion (Control * c)
{
    iniciarRuleta();
    iniciarControl(c);
}
void siguienteIteracion (Control *c, Reloj r)
{
    llegaCoche(c, r);
    marchaCoche(c, r);
}
void mostrarResultados (Control c)
{
    int i,cochesServidos, tiempoEsperado;
    float tiempoMedioEspera;
    cochesServidos = 0;
    tiempoEsperado = 0;
    for (i = 0; i<NCAB; i++)
    {
        printf("En la cabina %d: ", i+1);
        printf(" han estado esperando un máximo de %d coches", c.peaje[i].maxCoches);
        if (c.peaje[i].servidos != 0)
            printf(" y el tiempo medio de espera es de %d segundos.\n",(c.peaje[i].totalEsperado/c.peaje[i].servidos)); 
        else
            printf(" y los coches no han estado esperando nada\n");
        cochesServidos = cochesServidos+c.peaje[i].servidos;
        tiempoEsperado = tiempoEsperado+c.peaje[i].totalEsperado;
    }
    if (cochesServidos != 0)
    {
        tiempoMedioEspera = tiempoEsperado/cochesServidos;
        printf("Se han atendido a un total de %d coches. ", cochesServidos);
        printf("El tiempo medio esperado es de %.2f segundos", tiempoMedioEspera);
        tiempoMedioEspera = tiempoMedioEspera/60;
        printf(", %.3f en minutos.\n", tiempoMedioEspera);
    }
}
