#ifndef LISTADOBLE_H
#define LISTADOBLE_H
#include "NodoDoble.h"
template<class T>
class ListaDoble
{
    private:
        NodoDoble<T>* cola;
        NodoDoble<T>* actual;
        NodoDoble<T>* cabeza;
        int tamanio;
    public:
        ListaDoble();
        ~ListaDoble();
        void insertar(T dato);
        void agregarFinal(T dato);
        T eliminar();
        void vaciar();
        T obtenerElemento();
        void irInicio();
        void irFinal();
        void irPosicion();
        void siguiente();
        void anterior();
        bool alInicio();
        bool alFinal();
        int obtenerPosicion();
        int obtenerTamanio();

};

#endif // LISTADOBLE_H
