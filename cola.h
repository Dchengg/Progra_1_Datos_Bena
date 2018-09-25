#ifndef COLA_H
#define COLA_H

#include "Nodo.h"

template<class T>
class Cola
{
private:
    Nodo<T>* Tope;
    Nodo<T>* Fondo;
public:
    Cola();
    void push(T &x);
    void imprimirCola();
};

#endif // COLA_H
