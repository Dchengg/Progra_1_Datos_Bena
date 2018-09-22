#include <iostream>
#include <stdio.h>
#include "ListaSimple.h"

using namespace std;

template<class T>
ListaSimple<T>::ListaSimple()
{
    primero = 0;
}

template<class T>
void ListaSimple<T>::insertarNodo (T &x) {
    if(!primero){
        primero = new Nodo<T>(x);
    }else{
        Nodo<T>* aux = primero;
        while(aux->getSiguiente()){
            aux = aux->getSiguiente();
        }
        Nodo<T>* nuevo = new Nodo<T>(x);
        aux->setSiguiente(nuevo);
    }
}

template<class T>
void ListaSimple<T>::imprimirLista()
{
    Nodo<T>* tmp;
    tmp = primero;
    while(tmp){
       cout<<"->"<<tmp->getDato();
       tmp = tmp->getSiguiente();
    }
    cout<<endl;

}
