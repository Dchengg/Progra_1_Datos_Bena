#include <iostream>
#include <stdio.h>
#include "ListaSimple.h"


ListaSimple::ListaSimple()
{
    primero = 0;
}

void ListaSimple::insertarNodo (T &x) {
    NodoSimple<T> aux = primero;
    if(primero){
        primero = new NodoSimple<T>(x);
    }else{
        NodoSimple<T>* nuevo = new NodoSimple<T>(x);
        while(!aux->enlaceNodo){
            aux = aux->enlaceNodo;
        }
        aux->ponerEnlace(nuevo);
        aux = nuevo;
    }
}

void ListaSimple::imprimirLista()
{
    NodoSimple<T>* tmp;
    tmp = primero;
    while(tmp){
       cout<<"->"<<tmp->datoNodo();
       tmp = tmp->enlaceNodo();
    }
    cout<<endl;

}
