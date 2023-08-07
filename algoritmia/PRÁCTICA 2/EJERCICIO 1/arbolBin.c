#include "arbolBin.h"
void nuevoArbolBin(tipoArbolBin *a)
{
    *a = NULL;
}
void errorArbolBin(char s[])
{
    printf("\n\n\nERROR en el módulo arbol binario: %s \n", s);
	while (true)
		exit(-1);
}
bool esVacio(tipoArbolBin a)
{
    return (a==NULL);
}
tipoArbolBin construir(tipoElementoArbolBin elemento, tipoArbolBin hijoIzq, tipoArbolBin hijoDcha)
{
    tipoArbolBin padre;
    if ((padre = malloc(sizeof(tipoArbolBin))) == NULL)
        errorArbolBin("no hay memoria para pideTurno");
    padre->izda = hijoIzq;
    padre->dcha = hijoDcha;
    padre->elem = elemento;
    return padre;
}
tipoElementoArbolBin devolverRaiz(tipoArbolBin a)
{
    return (a->elem);
}
void preorden(tipoArbolBin a)
{
    if (!esVacio(a))
    {
        printf("%d", a->elem);
        preorden(a->izda);
        preorden(a->dcha);
    }
}
void inorden(tipoArbolBin a)
{
    if (!esVacio(a))
    {
        inorden(a->izda);
        printf("%d", a->elem);
        inorden(a->dcha);
    }
}
void postorden(tipoArbolBin a)
{
    if (!esVacio(a))
    {
        postorden(a->izda);
        postorden(a->dcha);
        printf("%d", a->elem);
    }
}
