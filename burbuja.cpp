#include "burbuja.h"
#include <iostream>
#include "Nodo.h"
using namespace std;

burbuja::burbuja()
{

}

template <class T>

void Burbuja(T *cabeza)
{
    int condicion;
    Nodo<T> *nodo1;
    Nodo<T> *nodo2 = NULL;
    if(!cabeza || !nodo1->getSiguiente())
    {
       return;
    }
    do {
        condicion=1;
        nodo1 = cabeza;
        while (!nodo1->getSiguiente())
        {
            condicion=0;
            if(nodo1->getDato() > nodo2->getDato())
            {
               swap(nodo1,nodo2);
               condicion=1;
            }
            nodo1 = nodo1->getSiguiente();
        }
        nodo2 = nodo1;
    }while(condicion);
}

template <class T>
void swap(Nodo<T>* nodo1, Nodo<T>* nodo2)
{
    T temporal = nodo1->getDato();
    nodo1 -> setDato(nodo2->getDato());
    nodo2 -> setDato(temporal);

}
