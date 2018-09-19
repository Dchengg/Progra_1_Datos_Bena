/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include <stdio.h>

using namespace std;

typedef int Dato;
#include "Nodo.h"

template<class T>
class Lista
{
private:

    Nodo<T>* primero;
    Nodo<T>* ultimo;
public:
    Lista()
    {
        primero = 0;
        ultimo = 0;
    }


    void insertarNodo (T &x) {

        if(primero == 0){
            primero = new Nodo<T>(x);
            ultimo = primero;
        }else{
            Nodo<T>* nuevo = new Nodo<T>(x);
            ultimo->ponerEnlace(nuevo);
            ultimo = nuevo;
        }
    }

    void imprimirLista()
    {
        Nodo<T>* tmp;
        tmp = primero;
        while(tmp){
           cout<<"->"<<tmp->datoNodo();
           tmp = tmp->enlaceNodo();
        };
        cout<<endl;

    }
};
