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
        NodoSimple<T>* aux = Tope;
        while(aux->enlaceNodo()){
            aux = aux->enlaceNodo();
        }
        NodoSimple<T>* nuevo = new NodoSimple<T>(x);
        aux->ponerEnlace(nuevo);
        Fondo = nuevo;
    }
}

template<class T>
void Cola<T>::imprimirCola()
{
    NodoSimple<T>* tmp;
    tmp = Tope;
    while(tmp){
       cout<<"->"<<tmp->datoNodo();
       tmp = tmp->enlaceNodo();
    }
    cout<<endl;

}
