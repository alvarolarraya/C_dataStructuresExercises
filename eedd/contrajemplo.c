/*
 *  Programa: euclides
 *  Fichero: euclides.c
 *  Hist—rico:
 *    Creado por Federico Fari–a Figueredo el 10/3/16.
 *      versi—n 1.0.0
 *    Modificado por Federico Fari–a Figueredo el 21/6/18
 *	     versi—n 1.0.1: Se cambia la documentaci—n a castellano y se actualiza
 *                     el formato de algunos comentarios. Tambien se desorganiza
 *                     todo para que sirva de ejemplo de algunas cosas buenas
 *                     (documentacion) y de contraejemplo de otras.
 *  Copyright © 2016 Federico Fari–a Figueredo. All rights reserved.
 */
/*
 *  Prototipos de las funciones.
 *  No es necesario incluirlas, pero su inclusi—n permite organizar el c—digo como
 *  se desee.
 */
/*
 * FUNCION mcdEduc
 * ENTRADA: a = A y b = B
 * REQUISITOS: A >= 0 y B >= 0
 * SALIDA:  mcd = m.c.d.(A,B)
 */
int mcdEduc(int a, int b);
typedef int numero; // Absurdo, pero para que veais que tambien es valido
int m; // HORROR, una variable global
#include <stdio.h> // Header de la libreria de C necesaria para la entrada
						 // salida de datos por teclado/pantalla
/*
 * FUNCION: calcula
 * ENTRADA: a = A y b = B
 * REQUISITOS: A > 0 y B > 0
 * SALIDA: (*mcm) = m.c.m.(A,B) y (*mcd) = m.c.d.(A,B)
 */
void calcula(int a, int b, int *mcm, int *mcd);
/*
 *	PROGRAMA PRINCIPAL
 *	ENTRADA: Por teclado, dos valores enteros
 *	REQUISITOS: El programa fuerza a que los valores sean positivos
 *	SALIDA: El programa saca por pantalla el maximo comun divisor y el minimo
 *      comun multiplo de los dos valores de entrada. Al finalizar devuelve
 *      el valor 0 (indicador de Žxito al SO)
 */
int main(void) {
	char quiereSalir;
	numero a[2], d;
	//
	printf("\tPrograma euclides\n");
	printf("\tCreado por Fitxi\n");
	printf("\tversion 1.0 (7/03/16)\n\n");
	printf("Este programa saca por pantalla el maximo cumun divisor y el\n");
	printf("minimo comun multiplo de dos enteros positivos que se \n");
	printf("suministran por el teclado\n\n");
	do {
		for(int i=0;i<2;i++){
			printf("Escriba el %s entero mayor que cero: ",(i==0?"primer":"segundo"));
			scanf("%d", &a[i]);
			if (a[i] <= 0)
				do {
					printf("No sabes leer? He dicho entero mayor que 0. Vuelve a intentarlo: ");
					scanf("%d", &a[i]);
				} while (a[i] <= 0);
		}
		calcula(a[0], a[1], &m, &d);
		printf("\tEl MCD de %d y %d es %d\n", a[0], a[1], d);
		printf("\tEl mcm de %d y %d es %d\n", a[0], a[1], m);
		printf("Si desea salir pulse s, para repetir la ejecucion cualquier otra cosa.");
		scanf("\n%c", &quiereSalir);
	} while (quiereSalir != 's');
	return 0;
}
int mcdEduc(int a, int b){
	if ((a==0) || (b==0))
		if (a > 0)
			return a;
		else
			return b;
	else
		if (a > b)
			return(mcdEduc(a-b, b));
		else if (a < b)
			return(mcdEduc(b-a,a));
		else
			return a;
}
void calcula(int m, int b, int* mcm, int* mcd){
		*mcd = mcdEduc(m, b);
		*mcm = (m*b) / *mcd;
}



