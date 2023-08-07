/*
  FICHERO: secuenciaEnteros.h
  VERSION: 1.0.0
  HISTORICO:
  Creado por Álvaro Larraya el 24/09/20.
*/

#include "secuenciaEnteros.h"
void nuevaSecuencia(tipoSecuencia* s)
{
      nuevaPila(&s->pilaIzq);
      nuevaPila(&s->pilaDcha);
      return;
}
void insertarDelantePunto(tipoSecuencia* s, tipoElementoPila e)
{
    apilar(&s->pilaIzq, e);
    return;
}
void insertarEnPunto(tipoSecuencia* s, tipoElementoPila e)
{
    apilar(&s->pilaDcha, e);
    return;
}
void eliminarEnPunto(tipoSecuencia* s)
{
    desapilar(&s->pilaDcha);
    return;
}
tipoElementoPila consultarEnPunto(tipoSecuencia s)
{
    return cima(s.pilaDcha);
}
void avanzarPunto (tipoSecuencia* s)
{
    apilar(&s->pilaIzq, cima(s->pilaDcha));
    desapilar(&s->pilaDcha);
    return;
}
void moverPuntoAlPrincipio (tipoSecuencia* s)
{
    while(!esNulaPila(s->pilaIzq))
    {
        apilar(&s->pilaDcha, cima(s->pilaIzq));
        desapilar(&s->pilaIzq);
    }
    return;
}
bool esPuntoUltimo(tipoSecuencia s)
{
    return esNulaPila(s.pilaIzq);
}
bool esVaciaSecuencia(tipoSecuencia s)
{
    return(esNulaPila(s.pilaIzq) && esNulaPila(s.pilaDcha));
}
