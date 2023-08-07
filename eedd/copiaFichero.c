/**
 *	PROGRAMA: copiaFichero
 *	FICHERO: copiaFichero.c
 *	VERSION: 1.0.0
 *	HISTORICO:
 *		Creado por Federico Fariña Figueredo el 01/03/19.
 * DESCRIPCION: Ejemplo de uso de un modulo
 *
 *  Este fichero se crea sólo con intenciones de coordinación
 *  docente y como ejemplo para los alumnos. El autor desautoriza expresamente
 *  su difusión, copia o exhibición pública.
 */
/*
 * ENTRADA: por teclado, el combre de un fichero de caracteres
 * SALIDA: crea el fichero copia con una copia del fichero de entrada
 */
#include "ficheroDeCaracteres.h"
#include <stdio.h>
int main(){
	FicheroDeCaracteres f, fcopia;
	char nombre[50];
	char x;
	printf("Nombre del fichero a copar: ");
	scanf("%s", nombre);
	asociarConArchivoFichCar(&f,nombre);
	asociarConArchivoFichCar(&fcopia,"copia");
	abrirLecFichCar(&f);
	abrirEscFichCar(&fcopia);
	while (!fdfFichCar(f)){
		leerFichCar(&f, &x);
		escribirFichCar(&fcopia, x);
	}
	cerrarFichCar(&f);
	cerrarFichCar(&fcopia);
}
