#include "ListaSimple.cpp"

template<class T>
void insertion(T *cabeza) {
    if(!cabeza || !cabeza->getSiguiente()) {
       return;
    }
    T* t1 = cabeza->getSiguiente();
    while(t1) {
        typename T::type sec_data = t1->getDato();
        int found = 0;
        T* t2 = cabeza;
        while(t2 != t1) {
            if(t2->getDato() > t1->getDato() && found == 0) {
                sec_data = t2->getDato();
                t2->setDato(t1->getDato());
                found = 1;
                t2 = t2->getSiguiente();
            } else {
                if(found == 1) {
                    typename T::type temp = sec_data;
                    sec_data = t2->getDato();
                    t2->setDato(temp);
                }
                t2 = t2->getSiguiente();
            }
       }
       t2->setDato(sec_data);
       t1 = t1->getSiguiente();
    }
}

void auxBurbuja(NodoSimple<int>* nodo1,NodoSimple<int>* nodo2,int &flag){
    if(nodo1->getDato() > nodo2->getDato()){
        int tmp = nodo1->getDato();
        nodo1->setDato(nodo2->getDato());
        nodo2->setDato(tmp);
        flag = 0;
    }
    if(nodo2->getSiguiente()){
        auxBurbuja(nodo1->getSiguiente(),nodo2->getSiguiente(),flag);
        if(nodo1->getDato() > nodo2->getDato()){
            int tmp = nodo1->getDato();
            nodo1->setDato(nodo2->getDato());
            nodo2->setDato(tmp);
            flag = 0;
        }
    }
}

void biBurbuja(NodoSimple<int>* cabeza){
    if(!cabeza || !cabeza->getSiguiente()) {
       return;
    }
    NodoSimple<int>* aux1 = cabeza;
    NodoSimple<int>* aux2 = cabeza->getSiguiente();
    int flag = 0;
    while(!flag || aux2){
       flag = 1;
       auxBurbuja(aux1,aux2,flag);
       aux1 = aux1->getSiguiente();
       aux2= aux2->getSiguiente();
    }

}


