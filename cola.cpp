#include "cola.h"

Cola::Cola()
{

}

#include "NodoSimple.h"

template<class T>
class ListaSimple
{
private:

    NodoSimple<T>* primero;
    NodoSimple<T>* ultimo;
public:
    ListaSimple()
    {
        primero = 0;
        ultimo = 0;
    }


    void insertarNodo (T &x) {

        if(primero == 0){
            primero = new NodoSimple<T>(x);
            ultimo = primero;
        }else{
            NodoSimple<T>* nuevo = new NodoSimple<T>(x);
            ultimo->ponerEnlace(nuevo);
            ultimo = nuevo;
        }
    }

    void imprimirLista()
    {
        NodoSimple<T>* tmp;
        tmp = primero;
        while(tmp){
           cout<<"->"<<tmp->datoNodo();
           tmp = tmp->enlaceNodo();
        };
        cout<<endl;

    }
};
