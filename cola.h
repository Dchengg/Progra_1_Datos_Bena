#ifndef COLA_H
#define COLA_H

#include "NodoSimple.h"

template<class T>
class Cola
{
private:
    NodoSimple<T>* Tope;
    NodoSimple<T>* Fondo;
public:
    Cola();
    void push(T &x);
    void imprimirCola();
};

#endif // COLA_H
