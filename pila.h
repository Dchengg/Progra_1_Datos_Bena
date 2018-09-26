#ifndef PILA_H
#define PILA_H
#include "Nodo.h"

template<class T>
class pila
{
private:
    Nodo<T>* Tope;
    Nodo<T>* Fondo;
public:
    pila();
    void push(T &x);
    void imprimirPila();
};

#endif // PILA_H
