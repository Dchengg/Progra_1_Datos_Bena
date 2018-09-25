#ifndef LISTA_SIMPLE_H
#define LISTA_SIMPLE_H

#include "Nodo.h"

template<class T>
class ListaSimple
{
    public:
        Nodo<T>* primero;
    public:
        ListaSimple();
        void insertarNodo (T &x);
        void imprimirLista();
};


#endif // ListaSimple_H

