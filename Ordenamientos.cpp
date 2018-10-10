#include "ListaSimple.cpp"
#include "ListaDoble.cpp"
#include <vector>

template<class T>
ListaDoble<T*>* insertion(T* TDA) {
    ListaDoble<T*>* pasos = new ListaDoble<T*>();
    if(!TDA->primero || !TDA->primero->getSiguiente()) {
       return pasos;
    }
    Nodo<typename T::type>* t1 = TDA->primero->getSiguiente();
    while(t1) {
        typename T::type sec_data = t1->getDato();
        int found = 0;
        Nodo<typename T::type>* t2 = TDA->primero;
        while(t2 != t1) {
            if(t2->getDato() > t1->getDato() && found == 0) {
                sec_data = t2->getDato();
                t2->setDato(t1->getDato());
                T* copia = new T(*TDA);
                pasos->insertarNodo(copia);
                found = 1;
                t2 = t2->getSiguiente();
            } else {
                if(found == 1) {
                    typename T::type temp = sec_data;
                    sec_data = t2->getDato();
                    t2->setDato(temp);
                    T* copia = new T(*TDA);;
                    pasos->insertarNodo(copia);
                }
                t2 = t2->getSiguiente();
            }
       }
       t2->setDato(sec_data);
       t1 = t1->getSiguiente();
    }
    return pasos;
}

template<class T>
void auxBurbuja(T* TDA,Nodo<typename T::type>*nodo1,Nodo<typename T::type>* nodo2,int &flag,ListaDoble<T*>* pasos){
    if(nodo1->getDato() > nodo2->getDato()){
        typename T::type tmp = nodo1->getDato();
        nodo1->setDato(nodo2->getDato());
        nodo2->setDato(tmp);
        flag = 0;
        T* copia = new T(*TDA);
        pasos->insertarNodo(copia);
    }
    if(nodo2->getSiguiente()){
        auxBurbuja(TDA,nodo1->getSiguiente(),nodo2->getSiguiente(),flag,pasos);
        if(nodo1->getDato() > nodo2->getDato()){
            typename T::type tmp = nodo1->getDato();
            nodo1->setDato(nodo2->getDato());
            nodo2->setDato(tmp);
            flag = 0;
            T* copia = new T(*TDA);
            pasos->insertarNodo(copia);
        }
    }
}

template<class T>
ListaDoble<T*>* biBurbuja(T* TDA){
    ListaDoble<T*>* pasos = new ListaDoble<T*>();
    if(!TDA->primero || !TDA->primero->getSiguiente()) {
       return pasos;
    }
    Nodo<typename T::type>* aux1 = TDA->primero;
    Nodo<typename T::type>* aux2 = TDA->primero->getSiguiente();
    int flag = 0;
    while(!flag || aux2){
       flag = 1;
       auxBurbuja(TDA,aux1,aux2,flag,pasos);
       aux1 = aux1->getSiguiente();
       aux2= aux2->getSiguiente();
    }
    return pasos;
}

template<class T>
void intercambio(T* nodo1, T* nodo2){
    typename T::type temp = nodo1->getDato();
    nodo1->setDato(nodo2->getDato());
    nodo2->setDato(temp);

}


template<class T>
void heapify(T &l1, int n, int i,ListaDoble<T*>* pasos)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;


    if (l < n && l1[l]->getDato() > l1[largest]->getDato())
        largest = l;


    if (r < n && l1[r]->getDato() > l1[largest]->getDato())
        largest = r;


    if (largest != i)
    {
        intercambio(l1[i], l1[largest]);
        T* copia = new T(l1);
        pasos->insertarNodo(copia);


        heapify(l1, n, largest,pasos);
    }
}

template<class T>
ListaDoble<T*>* heapSort(T &l1)
{
    ListaDoble<T*>* pasos = new ListaDoble<T*>();
    int n = l1.getTam();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(l1, n, i,pasos);


    for (int i=n-1; i>=0; i--)
    {

        intercambio(l1[0], l1[i]);
        T* copia = new T(l1);
        pasos->insertarNodo(copia);


        heapify(l1, i, 0,pasos);
    }
    return pasos;
}

template<class T>
int getMax(T l1, int n)
{
    typename T::type mx = l1[0]->getDato();
    for (int i = 1; i < n; i++)
        if (l1[i]->getDato() > mx)
            mx = l1[i]->getDato();
    return mx;
}


template <class T>
void countSort(T &l1, int n, int exp,ListaDoble<T*>* pasos)
{
    int output[n];
    int i, count[10] = {0};


    for (i = 0; i < n; i++)
        count[ (l1[i]->getDato()/exp)%10 ]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (l1[i]->getDato()/exp)%10 ] - 1] = l1[i]->getDato();
        count[ (l1[i]->getDato()/exp)%10 ]--;
    }


    for (i = 0; i < n; i++){
        l1[i]->setDato(output[i]);
        T* copia = new T(l1);
        pasos->insertarNodo(copia);
    }

}


template<class T>
ListaDoble<T*>* radixsort(T &l1)
{
    ListaDoble<T*>* pasos = new ListaDoble<T*>();
    int n = l1.getTam();

    typename T::type m = getMax(l1, n);


    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(l1, n, exp,pasos);
    return pasos;
}


template<class T>
int partition (T &l1, int low, int high,ListaDoble<T*>* pasos)
{
    typename T::type pivot = l1[high]->getDato();
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {

        if (l1[j]->getDato() <= pivot)
        {
            i++;
            intercambio(l1[i], l1[j]);
            T* copia = new T(l1);
            pasos->insertarNodo(copia);

        }
    }
    T* copia = new T(l1);
    pasos->insertarNodo(copia);
    intercambio(l1[i + 1], l1[high]);
    return (i + 1);
}

template<class T>
ListaDoble<T*>* quickSort(T &l1, int low, int high, ListaDoble<T*>* pasos = new ListaDoble<T*>())
{

    if (low < high)
    {

        int pi = partition(l1, low, high,pasos);


        quickSort(l1, low, pi - 1,pasos);
        quickSort(l1, pi + 1, high,pasos);
    }
    return pasos;
}
//===================SELECTION=SORT=================================
template <class T>
ListaDoble<T*>* SelectionSort(T* TDA){
    ListaDoble<T*>* pasos =  new ListaDoble<T*>();
    Nodo<typename T::type>* posicion = TDA->primero;
    while(posicion != NULL){
        Nodo<typename T::type>* menor = posicion;
        Nodo<typename T::type>* temp = posicion;
        while(temp != NULL){
            if(temp->getDato() < menor->getDato()){
                menor = temp;
            }
            temp = temp->getSiguiente();
        }
        intercambio(posicion, menor);
        T* copia = new T(*TDA);
        pasos->insertarNodo(copia);
        posicion = posicion->getSiguiente();
    }
    return pasos;
}
//===================BUBBLE=SORT=================================

template <class T>
inline ListaDoble<T*>* Burbuja(T* lista)
{
    int condicion;
    ListaDoble<T*>* pasos = new ListaDoble<T*>();
    Nodo<typename T::type>* nodo1 = lista->primero;
    Nodo<typename T::type>* nodo2 = NULL;
    if(!lista->primero || !nodo1->getSiguiente())
    {
       return pasos;
    }
    do {
        condicion=0;
        nodo1 = lista->primero;
        while (nodo1->getSiguiente() )
        {
            if(nodo1->getDato() > nodo1->getSiguiente()->getDato())
            {
               intercambio(nodo1,nodo1->getSiguiente());
               condicion=1;
               T* copia = new T(*lista);;
               pasos->insertarNodo(copia);

            }
            nodo1 = nodo1->getSiguiente();
        }
        nodo2 = nodo1;
    }while(condicion);
    return pasos;
}
//===================SHELL=SORT=================================

template <class T>
ListaDoble<T*>* ShellSort(T* TDA)
{
    ListaDoble<T*>* pasos = new ListaDoble<T*>();
    if(TDA->primero)
    {
        int step=0;
        int lenght=0;
        Nodo<typename T::type>* puntero= TDA->primero;
        while(puntero)
        {
            lenght++;
            puntero=puntero->getSiguiente();
        }
        while(2*(3*step+1)<=lenght)
            step=3*step+1;
        for(step;step>0;step/=3)
            for(int i=step;i>0;i--)
                for(int j=step-i; j<lenght; j+=step)
                {
                    puntero= TDA->primero;
                    int k;
                    for(k=0;k<j;k++)
                        puntero=puntero->getSiguiente();
                    Nodo<typename T::type>* c=puntero;
                    int temp=k+step;
                    while(c)
                    {
                        for(k;k<temp;)
                            if(c)
                            {
                                k++;
                                c=c->getSiguiente();
                            }
                            else break;
                            if(c)
                                if(puntero->getDato()>c->getDato())
                                {
                                    int t = puntero->getDato();
                                    puntero->setDato(c->getDato());
                                    c->setDato(t);
                                    //ListaSimple<typename T::type>* copia = new ListaSimple<int>(*TDA);
                                    T* copia = new T(*TDA);
                                    pasos->insertarNodo(copia);
                                }
                                temp+=step;
                    }
                }
    }
    return pasos;
}
//===================MERGE=SORT=================================
template<class T>
inline void merge(T &lista, int l, int m, int r,ListaDoble<T*>* pasos)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = lista[l + i]->getDato();
    for (j = 0; j < n2; j++)
        R[j] = lista[m + 1+ j]->getDato();

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            lista[k]->setDato(L[i]);
            i++;
            //ListaSimple<typename T::type>* copia = new ListaSimple<int>(lista);
            T* copia = new T(lista);
            pasos->insertarNodo(copia);
        }
        else
        {
            lista[k]->setDato(R[j]);
            j++;
            //ListaSimple<typename T::type>* copia = new ListaSimple<int>(lista);
            T* copia = new T(lista);
            pasos->insertarNodo(copia);
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        lista[k]->setDato(L[i]);
        i++;
        k++;
        //ListaSimple<typename T::type>* copia = new ListaSimple<int>(lista);
        T* copia = new T(lista);
        pasos->insertarNodo(copia);
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        lista[k]->setDato(R[j]);
        j++;
        k++;
        //ListaSimple<typename T::type>* copia = new ListaSimple<int>(lista);
        T* copia = new T(lista);
        pasos->insertarNodo(copia);
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
template<class T>
inline ListaDoble<T*>* mergeSort(T &l1, int l, int r,ListaDoble<T*>* pasos = new ListaDoble<T*>())
{

    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(l1, l, m,pasos);
        mergeSort(l1, m+1, r,pasos);

        merge(l1, l, m, r,pasos);
    }

    return pasos;
}
//===================BIN=SORT=================================
/*void bucketSort(ListaSimple<int> lista)
{
    // 1) Create n empty buckets
    int n =  lista.getTam()-1;
    vector<int> b[n];  //cambiar a typename T::type

    // 2) Put array elements in different buckets
    for (int i=0; i<n; i++)
    {
       int bi = n * lista[i]->getDato(); // Index in bucket
       b[bi].push_back(lista[i]->getDato());
    }

    // 3) Sort individual buckets
    for (int i=0; i<n; i++)
       sort(b[i].begin(), b[i].end());

    // 4) Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < b[i].size(); j++)
          lista[index++] = b[i][j];
}
*/
