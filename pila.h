#ifndef PILA_H
#define PILA_H
#include "Nodo.h"

template<class T>
class pila
{
private:
    Nodo<T>* Tope;
    Nodo<T>* Fondo;
    int tam;
public:
    pila();
    void push(T &x);
    void imprimirPila();
    int getTam();
    Nodo<T>* operator[](int const index);
};

#endif // PILA_H
