#ifndef NODODOBLE_H
#define NODODOBLE_H

template<class T>
class NodoDoble
{
    private:
        T dato;
        NodoDoble<T>* siguiente;
        NodoDoble<T>* anterior;
    public:
        NodoDoble(T dato, NodoDoble<T>* anterior, NodoDoble<T>* siguiente)
        {
            this.dato= dato;
            this.siguiente=siguiente;
            this.anterior=anterior;
        }

        NodoDoble(NodoDoble<T>* anterior, NodoDoble<T>* siguiente)
        {
            this.siguiente=siguiente;
            this.anterior=anterior;
        }

        T datoNodo()
        {
            return dato;
        }

        void ponerSiguiente(NodoDoble<T>* siguiente)
        {
            this.siguiente=siguiente;

        }

        NodoDoble obtenerSiguiente()
        {
            return siguiente;
        }

        void ponerAnterior(NodoDoble<T>* anterior)
        {
            this.anterior=anterior;

        }

        NodoDoble obtenerAnterior()
        {
           return anterior;
        }

};

#endif // NODODOBLE_H
