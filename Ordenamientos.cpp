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

template<class T>
void auxBurbuja(T *nodo1,T *nodo2,int &flag){
    if(nodo1->getDato() > nodo2->getDato()){
        typename T::type tmp = nodo1->getDato();
        nodo1->setDato(nodo2->getDato());
        nodo2->setDato(tmp);
        flag = 0;
    }
    if(nodo2->getSiguiente()){
        auxBurbuja(nodo1->getSiguiente(),nodo2->getSiguiente(),flag);
        if(nodo1->getDato() > nodo2->getDato()){
            typename T::type tmp = nodo1->getDato();
            nodo1->setDato(nodo2->getDato());
            nodo2->setDato(tmp);
            flag = 0;
        }
    }
}

template<class T>
void biBurbuja(T *cabeza){
    if(!cabeza || !cabeza->getSiguiente()) {
       return;
    }
    T* aux1 = cabeza;
    T* aux2 = cabeza->getSiguiente();
    int flag = 0;
    while(!flag || aux2){
       flag = 1;
       auxBurbuja(aux1,aux2,flag);
       aux1 = aux1->getSiguiente();
       aux2= aux2->getSiguiente();
    }

}

void swap(Nodo<int>* nodo1, Nodo<int>* nodo2){
    int temp = nodo1->getDato();
    nodo1->setDato(nodo2->getDato());
    nodo2->setDato(temp);

}
// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(ListaSimple<int> l1, int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2*i + 1; // left = 2*i + 1
    int r = 2*i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && l1[l]->getDato() > l1[largest]->getDato())
        largest = l;

    // If right child is larger than largest so far
    if (r < n && l1[r]->getDato() > l1[largest]->getDato())
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        swap(l1[i], l1[largest]);

        // Recursively heapify the affected sub-tree
        heapify(l1, n, largest);
    }
}

// main function to do heap sort
void heapSort(ListaSimple<int> l1)
{
    int n = l1.getTam();
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(l1, n, i);

    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
        swap(l1[0], l1[i]);

        // call max heapify on the reduced heap
        heapify(l1, i, 0);
    }

}
