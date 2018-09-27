#include <iostream>
#include <stdio.h>
#include "cola.h"

using namespace std;

template<class T>
Cola<T>::Cola()
{
    Tope = 0;
    Fondo = 0;
}
template <class T>
void Cola<T>::push(T &x){
    if(!Tope){
        Tope = new Nodo<T>(x);
        Fondo = Tope;
    }else{
        Nodo<T>* nuevo = new Nodo<T>(x);
        nuevo->setSiguiente(Tope);
        Tope = nuevo;
    }
}

template<class T>
void Cola<T>::imprimirCola()
{
    Nodo<T>* tmp;
    tmp = Tope;
    while(tmp){
       cout<<"->"<<tmp->getDato();
       tmp = tmp->getSiguiente();
    }
    cout<<endl;

}

template<class T>
int Cola<T>::getTam()
{
    return tam;
}

template<class T>
Nodo<T>* Cola<T>::operator[](int const index) {
    Nodo<T>* aux =Tope;
    for (int i = 0; i < index; i++) {
        aux = aux->getSiguiente();
    }
    return aux;
}

