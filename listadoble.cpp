#include "ListaDoble.h"
#include <stdio.h>
#include <iostream>
using namespace std;

template<class T>
ListaDoble<T>::ListaDoble() //
{
    primero = 0;
    tam = 0;
}

template<class T>
ListaDoble<T>::ListaDoble(ListaDoble<T> const &original){
    primero = 0;
    tam = 0;
    Nodo<T>* aux = original.primero;
    while(aux){
        int dato = aux->getDato();
        insertarNodo(dato);
        aux = aux->getSiguiente();
    }
}

template<class T>
void ListaDoble<T>::insertarNodo (T &dato)
{
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
    tam++;
}

template<class T>
void ListaDoble<T>::imprimirLista()
   {
        Nodo<T>* temp;
        temp = primero;
        while(temp){
           cout<<"<->"<<temp->getDato();
           temp = temp->getSiguiente();
        }
        cout<<endl;
    }

template<class T>
int ListaDoble<T>::getTam()
{
    return tam;
}

template<class T>
Nodo<T>* ListaDoble<T>::operator[](int const index) {
    Nodo<T>* aux = primero;
    for (int i = 0; i < index; i++) {
        aux = aux->getSiguiente();
    }
    return aux;
}

