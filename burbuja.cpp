#include "burbuja.h"
#include <iostream>
#include "Nodo.h"
using namespace std;

burbuja::burbuja()
{

}

template <class T>

void BurbujaP(T *cabeza)
{
    if(!cabeza || !cabeza->getSiguiente())
    {
       return;
    }
}

template <class T>
void BurbujaS(T *nodo1,T *nodo2,int &flag)
{
    if(nodo1->getDato() > nodo2->getDato())
    {
        typename T::type temporal = nodo1->getDato();
        nodo1->setDato(nodo2->getDato());
        nodo2->setDato(temporal);
        flag = 0;
    }
    if(nodo2->getSiguiente())
    {
        if(nodo1->getDato() > nodo2->getDato())
        {
            typename T::type temporal = nodo1->getDato();
            nodo1->setDato(nodo2->getDato());
            nodo2->setDato(temporal);
            flag = 0;
        }
    }
}

template <class T>
void swap(Nodo<T>* nodo1, Nodo<T>* nodo2)
{
    T temporal = nodo1->getDato();
    nodo1 -> setDato(nodo2->getDato());
    nodo2 -> setDato(temporal);

}
