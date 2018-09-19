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
class NodoSimple
{
private:
    T dato;
    NodoSimple* enlace;
public:
    
    NodoSimple(T valor)
    {
    dato = valor;
    enlace = 0; // 0 es el puntero NULL en C++
    }
    
    NodoSimple(T p, NodoSimple* n) // crea el nodo y lo enlaza a n
    {
    dato = p;
    enlace = n;
    }
    
    T datoNodo()
    {
        return dato;
    }
    NodoSimple* enlaceNodo() const
    {
        return enlace;
    }
    void ponerEnlace(NodoSimple* sgte)
    {
        enlace = sgte;
    }


};


#endif /* NODO_H */
