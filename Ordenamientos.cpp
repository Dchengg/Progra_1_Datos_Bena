#include "ListaSimple.cpp"

template<class T>
void insertion(T *head) {
    if(!head || !head->getSiguiente()) {
       return;
    }
    T* t1 = head->getSiguiente();
    while(t1) {
        typename T::type sec_data = t1->getDato();
        int found = 0;
        T* t2 = head;
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
