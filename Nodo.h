/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.h
 * Author: bryan
 *
 * Created on 29 de agosto de 2018, 09:05 AM
 */


#ifndef NODO_H
#define NODO_H


template <class T>
class Nodo
{
private:
    T dato;
    Nodo* enlace;
public:
    
    Nodo(T t)
    {
    dato = t;
    enlace = 0; // 0 es el puntero NULL en C++
    }
    
    Nodo(T p, Nodo* n) // crea el nodo y lo enlaza a n
    {
    dato = p;
    enlace = n;
    }
    
    T datoNodo()
    {
        return dato;
    }
    Nodo* enlaceNodo() const
    {
        return enlace;
    }
    void ponerEnlace(Nodo* sgte)
    {
        enlace = sgte;
    }


};


#endif /* NODO_H */

