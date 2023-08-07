#include "minMonticulo.h"
void nuevoMinMonticulo(tipoMinMonticulo* m, int numeroCeldas)
{
    if ((m = malloc(sizeof(tipoMinMonticulo))) == NULL)
        perror("no hay memoria para reservar el minMonticulo\n");
    if ((m->array = malloc(numeroCeldas*sizeof(tipoElementoMinMonticulo*))) == NULL)
        perror("no hay memoria para reservar el array de minMonticulo\n");
    m->pos = 0;
    m->numEl = numeroCeldas;
}
void errorMinMonticulo(char s[])
{
    printf("\n\n\nERROR en el módulo minMonticulo: %s \n", s);
	while (true)
		exit(-1);
}
void insertarMinMonticulo(tipoMinMonticulo *m, tipoElementoMinMonticulo elemento)
{
    int i;
    //si esta vacío meto el elemento
    if(m->pos == 0)
    {
        m->pos++;
        m->array[0] = elemento;
        return;
    }
    //inserto el elemento de tal forma que m siga siendo completo
    m->array[m->pos] = elemento;
    i = m->pos;
    m->pos++;
    //recoloco el elemento en la posicion que le toque
    //mientras que el elemento que sea menor que su padre los intercambio
    printf("%d", i/2);
    while (elemento < m->array[i/2]);
    {
        tipoElementoMinMonticulo aux;
        aux = m->array[i];
        m->array[i] = m->array[i/2];
        m->array[i/2] = aux;
    }
}
void eliminarElemento(tipoMinMonticulo *m, tipoElementoMinMonticulo elemento)
{
    
}
tipoElementoMinMonticulo devolverRaiz(tipoMinMonticulo m)
{
    
}
void mostrarAnchura(tipoMinMonticulo m)
{
    
}
bool esVacio(tipoMinMonticulo m)
{
    
}
bool estaLleno(tipoMinMonticulo m)
{
    
}
