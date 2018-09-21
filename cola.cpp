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
        Tope = new NodoSimple<T>(x);
        Fondo = Tope;
    }else{
        NodoSimple<T>* nuevo = new NodoSimple<T>(x);
        nuevo->setSiguiente(Tope);
        Tope = nuevo;
    }
}

template<class T>
void Cola<T>::imprimirCola()
{
    NodoSimple<T>* tmp;
    tmp = Tope;
    while(tmp){
       cout<<"->"<<tmp->getDato();
       tmp = tmp->getSiguiente();
    }
    cout<<endl;

}
