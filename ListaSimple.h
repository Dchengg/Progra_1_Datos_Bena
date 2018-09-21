#ifndef LISTA_H
#define LISTA_H

typedef int Dato;
#include "NodoSimple.h"

template<class T>
class ListaSimple
{
    public:
    NodoSimple<T>* primero;
public:
    ListaSimple();
    void insertarNodo (T &x);
    void imprimirLista();
};


#endif // ListaSimple_H

