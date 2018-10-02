#include "ListaSimple.cpp"
#include <vector>

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

template<class T>
void intercambio(T* nodo1, T* nodo2){
    typename T::type temp = nodo1->getDato();
    nodo1->setDato(nodo2->getDato());
    nodo2->setDato(temp);

}


// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
template<class T>
void heapify(T l1, int n, int i)
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
        intercambio(l1[i], l1[largest]);

        // Recursively heapify the affected sub-tree
        heapify(l1, n, largest);
    }
}

template<class T>
// main function to do heap sort
void heapSort(T l1)
{
    int n = l1.getTam();
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(l1, n, i);

    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
        intercambio(l1[0], l1[i]);

        // call max heapify on the reduced heap
        heapify(l1, i, 0);
    }

}

// A utility function to get maximum value in arr[]
template<class T>
int getMax(T l1, int n)
{
    typename T::type mx = l1[0]->getDato();
    for (int i = 1; i < n; i++)
        if (l1[i]->getDato() > mx)
            mx = l1[i]->getDato();
    return mx;
}

// A function to do counting sort of arr[] according to
// the digit represented by exp.
template <class T>
void countSort(T l1, int n, int exp)
{
    int output[n]; // output array
    int i, count[10] = {0};

    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[ (l1[i]->getDato()/exp)%10 ]++;

    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    // Build the output array
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (l1[i]->getDato()/exp)%10 ] - 1] = l1[i]->getDato();
        count[ (l1[i]->getDato()/exp)%10 ]--;
    }

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        l1[i]->setDato(output[i]);
}

// The main function to that sorts arr[] of size n using
// Radix Sort
template<class T>
void radixsort(T l1)
{
    int n = l1.getTam();
    // Find the maximum number to know number of digits
    typename T::type m = getMax(l1, n);

    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(l1, n, exp);
}

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
template<class T>
int partition (T l1, int low, int high)
{
    typename T::type pivot = l1[high]->getDato();    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (l1[j]->getDato() <= pivot)
        {
            i++;    // increment index of smaller element
            intercambio(l1[i], l1[j]);
        }
    }
    intercambio(l1[i + 1], l1[high]);
    return (i + 1);
}

/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
template<class T>
void quickSort(T l1, int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(l1, low, high);

        // Separately sort elements before
        // partition and after parti    tion
        quickSort(l1, low, pi - 1);
        quickSort(l1, pi + 1, high);
    }
}
//===================SELECTION=SORT=================================
template <class T>
void SelectionSort(T head){ //r is the pointer to the first node
    T posicion = head;
    while(posicion != NULL){
        T menor = posicion;
        T temp = posicion;
        while(temp != NULL){
            if(temp->getDato() < menor->getDato()){
                menor = temp;
            }
            temp = temp->getSiguiente();
        }
        intercambio(posicion, menor);
        posicion = posicion->getSiguiente();
    }
}
//===================BUBBLE=SORT=================================
template <class T>

void Burbuja(T cabeza)
{
    int condicion;
    T nodo1 = cabeza;
    T nodo2 = NULL;
    if(!cabeza || !nodo1->getSiguiente())
    {
       return;
    }
    do {
        condicion=0;
        nodo1 = cabeza;
        while (nodo1->getSiguiente() )
        {
            if(nodo1->getDato() > nodo1->getSiguiente()->getDato())
            {
               intercambio(nodo1,nodo1->getSiguiente());
               condicion=1;
            }
            nodo1 = nodo1->getSiguiente();
        }
        nodo2 = nodo1;
    }while(condicion);
}
//===================SHELL=SORT=================================

template <class T>
void ShellSort(T cabeza)
{
    if(cabeza)
    {
        int step=0;
        int lenght=0;
        T puntero=cabeza;
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
                    puntero=cabeza;
                    int k;
                    for(k=0;k<j;k++)
                        puntero=puntero->getSiguiente();
                    T c=puntero;
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
                                    int t=puntero->getDato();
                                    puntero->getDato()=c->getDato();
                                    c->getDato()=t;
                                }
                                temp+=step;
                    }
                }
    }
    cout<<"Sorting is done"<<endl;
}
//===================MERGE=SORT=================================
/*template <class T>
void MergeSort(T **head)
{
    T first = new Nodo<T>;
    T second = new Nodo<T>;
    T temp = new Nodo<T>;
    first = *head;
    temp = *head;

    // Return if list have less than two nodes.
    if(first == NULL || first->next == NULL)
    {
        return;
    }
    else
    {
        // Break the list into two half as first and second as head of list.
        while(first->next != NULL)
        {
            first = first->next;
            if(first->next != NULL)
            {
                temp = temp->next;
                first = first->next;
            }
        }
        second = temp->next;
        temp->next = NULL;
        first = *head;
    }

    // Implementing divide and conquer approach.
    MergeSort(&first);
    MergeSort(&second);

    // Merge the two part of the list into a sorted one.
    *head = Merge(first, second);
}*/
//mergeSort(*lista,0,lista->getTam()-1);
void merge(ListaSimple<int> lista, int l, int m, int r)
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
        }
        else
        {
            lista[k]->setDato(R[j]);
            j++;
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
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        lista[k]->setDato(R[j]);
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */

void mergeSort(ListaSimple<int> l1, int l, int r)
{

    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(l1, l, m);
        mergeSort(l1, m+1, r);

        merge(l1, l, m, r);
    }
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
