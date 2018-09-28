#include "pila.h"
#include <iostream>
#include <stdio.h>

using namespace std;

template<class T>
pila<T>::pila()
{
    Tope = 0;
    Fondo = 0;
    tam = 0;
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

template<class T>

int pila<T>::getTam()
{
    return tam;
}

template<class T>
Nodo<T>* pila<T>::operator[](int const index) {
    Nodo<T>* aux = Tope;
    for (int i = 0; i < index; i++) {
        aux = aux->getSiguiente();
    }
    return aux;
}

