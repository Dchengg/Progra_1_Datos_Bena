/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Lista.h
 * Author: bryan
 *
 * Created on 29 de agosto de 2018, 09:08 AM
 */

#ifndef LISTA_H
#define LISTA_H

typedef int Dato;
#include "Nodo.h"

class Lista
{
private:
    Nodo<* primero;
public:
    Lista();
    void crearLista();
    template <typename T>
    inline T insertarNodo (T &x);
    void imprimirLista();
};


#endif /* LISTA_H */

