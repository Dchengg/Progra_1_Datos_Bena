#include "pila.h"
#include <iostream>
#include <stdio.h>

using namespace std;

template<class T>
pila<T>::pila()
{
    Tope = 0;
    Fondo = 0;
}

template<class T>
void pila<T>::push(T &dato)
{
    if(!Tope)
    {
        Tope = new Nodo<T>(dato);
        Fondo = Tope;
    }
    else{
        Nodo<T>* nuevo = new Nodo<T>(dato);
        nuevo->setSiguiente(Tope);
        Tope = nuevo;
    }
}
