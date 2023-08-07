#include "arbolBinarioBusqueda.h"
int devolverRaiz(tipoArbolBB a);
void nuevoArbolBB(tipoArbolBB *a)
{
    *a = NULL;
}
void errorArbolBB(char s[])
{
    printf("\n\n\nERROR en el módulo arbol binario de busqueda: %s \n", s);
	while (true)
		exit(-1);
}
bool esVacio(tipoArbolBB a)
{
    return (a==NULL);
}
int devolverRaiz(tipoArbolBB a)
{
    return (a->elem);
}
void insertar(tipoArbolBB *a, tipoElementoArbolBusqueda elemento)
{
    if(*a == NULL)
    {
        celdaArbolBusqueda* hijo;
        if ((hijo = malloc(sizeof(celdaArbolBusqueda))) == NULL)
        errorArbolBB("no hay memoria para insertar\n");
        hijo->izda = NULL;
        hijo->dcha = NULL;
        hijo->elem = elemento;
        *a = hijo;
    }
    else
    {
        if (elemento > devolverRaiz(*a))
            insertar(&(*a)->dcha,elemento);
        else if (elemento < devolverRaiz(*a))
            insertar(&(*a)->izda,elemento);
        else
            printf("No se puede insertar, ya que el elemento ya estaba en el arbol binario de busqueda\n");
    }
}
void borrar(tipoArbolBB *a, tipoElementoArbolBusqueda elemento)
{
    tipoArbolBB sucesor,aux;
    if(*a == NULL)
        printf("No se ha encontrado el elemento");
    else if(devolverRaiz(*a) == elemento)
    {
        if ((*a)->dcha == NULL && (*a)->izda == NULL)
        {
            aux = *a;
            *a = NULL;
            free(aux);
        }
        else
        {
            tipoElementoArbolBusqueda aux_elem;
            if ((*a)->dcha != NULL && (*a)->izda == NULL)
            {
                aux = *a;
                *a = (*a)->dcha;
                free(aux);
            }
            else if((*a)->dcha == NULL && (*a)->izda != NULL)
            {
                aux = *a;
                *a = (*a)->izda;
                free(aux);
            }
            else
            {
                if((sucesor = malloc(sizeof(tipoArbolBB))) == NULL)
                    errorArbolBB("no hay memoria para utilizar un auxiliar sucesor para borrar\n");
                sucesor = (*a)->dcha;
                while(sucesor->izda != NULL)
                    sucesor = sucesor->izda;
                //Revisar esta parte
                aux_elem = sucesor->elem;
                borrar(&((*a)->dcha),aux_elem);
                (*a)->elem = aux_elem;
            }
        }
    }
    else
    {
        if(devolverRaiz(*a) < elemento)
            borrar(&(*a)->dcha,elemento);
        else
            borrar(&(*a)->izda,elemento);
    }
}
void mostrarPreorden(tipoArbolBB a)
{
    if (!esVacio(a))
    {
        printf("%d ", a->elem);
        mostrarPreorden(a->izda);
        mostrarPreorden(a->dcha);
    }
}
void mostrarInorden(tipoArbolBB a)
{
    if (!esVacio(a))
    {
        mostrarInorden(a->izda);
        printf("%d ", a->elem);
        mostrarInorden(a->dcha);
    }
}
void mostrarPostorden(tipoArbolBB a)
{
    if (!esVacio(a))
    {
        mostrarPostorden(a->izda);
        mostrarPostorden(a->dcha);
        printf("%d ", a->elem);
    }
}
