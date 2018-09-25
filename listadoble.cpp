#include "ListaDoble.h"
#include <stdio.h>
#include <iostream>
using namespace std;

template<class T>
ListaDoble<T>::ListaDoble() //
{
    primero = 0;
}

template<class T>
void ListaDoble<T>::insertarNodo (T &dato) {
    if(!primero)
    {
        primero = new Nodo<T>(dato);
    }
    else
    {
        Nodo<T>* auxiliar = primero;
        while(auxiliar->getSiguiente()){
            auxiliar = auxiliar->getSiguiente();
        }
        Nodo<T>* nuevo = new Nodo<T>(dato);
        auxiliar->setSiguiente(nuevo);
        nuevo->setAnterior(auxiliar);
    }
}

template<class T>
void ListaDoble<T>::imprimirLista()
   {
        Nodo<T>* temp;
        temp = primero;
        while(temp){
           cout<<"->"<<temp->getDato();
           temp = temp->getSiguiente();
        }
        cout<<endl;
    }

