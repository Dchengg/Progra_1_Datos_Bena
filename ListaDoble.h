#ifndef LISTA_DOBLE_H
#define LISTA_DOBLE_H

#include "Nodo.h"

template<class T>
class ListaDoble
{
    public:
        Nodo<T>* primero;
    public:
        ListaDoble();
        void insertarNodo (T &Dato);
        void imprimirLista();
};


#endif // ListaSimple_H

