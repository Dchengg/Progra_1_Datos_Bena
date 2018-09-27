#ifndef LISTA_SIMPLE_H
#define LISTA_SIMPLE_H

#include "Nodo.h"
#include <stdio.h>
#include <iostream>
using namespace std;

template<class T>
class ListaSimple
{
    public:
        Nodo<T>* primero;
        int tam;
    public:
        typedef T type;
        ListaSimple();
        void insertarNodo (T &x);
        void imprimirLista();
        int getTam();
        Nodo<T>* operator[](int const index);
};


#endif // ListaSimple_H

