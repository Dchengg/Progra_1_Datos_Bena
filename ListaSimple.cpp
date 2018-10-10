#include <iostream>
#include <stdio.h>
#include "ListaSimple.h"

using namespace std;

template<class T>
ListaSimple<T>::ListaSimple()
{
    primero = 0;
    tam = 0;
}

template<class T>
ListaSimple<T>::ListaSimple(ListaSimple<T> const &original){
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
void ListaSimple<T>::insertarNodo (T &dato) {
    if(!primero){
        primero = new Nodo<T>(dato);
    }else{
        Nodo<T>* aux = primero;
        while(aux->getSiguiente()){
            aux = aux->getSiguiente();
        }
        Nodo<T>* nuevo = new Nodo<T>(dato);
        aux->setSiguiente(nuevo);
    }
    tam++;
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
template<class T>
int ListaSimple<T>::getTam(){
    return tam;
}


template<class T>
Nodo<T>* ListaSimple<T>::operator[](int const index) {
    Nodo<T>* aux = primero;
    for (int i = 0; i < index; i++) {
        aux = aux->getSiguiente();
    }
    return aux;
}
