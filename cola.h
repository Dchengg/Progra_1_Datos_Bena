#ifndef COLA_H
#define COLA_H

#include "Nodo.h"

template<class T>
class Cola
{
private:
    Nodo<T>* Tope;
    Nodo<T>* Fondo;
    int tam;
public:
    typedef T type;
    Cola();
    Cola(Cola<T>  const &original);
    void push(T &x);
    void imprimirCola();
    int getTam();
    Nodo<T>* operator[](int const index);
};

#endif // COLA_H
