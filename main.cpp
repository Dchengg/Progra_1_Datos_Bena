#include "mainwindow.h"
#include <QApplication>




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ListaDoble<int>* lista = new ListaDoble<int>();
    int x = 5;
    lista->insertarNodo(x);
    x = 3;
    lista->insertarNodo(x);
    x = 9;
    lista->insertarNodo(x);
    x = 7;
    lista->insertarNodo(x);
    x = 1;
    lista->insertarNodo(x);
    x = 0;
    lista->insertarNodo(x);
    x = 99;
    lista->insertarNodo(x);
    x = 99;
    lista->insertarNodo(x);
    ListaDoble<ListaDoble<int>*>* pasos = mergeSort(*lista,0,lista->getTam()-1);
    Nodo<ListaDoble<int>*>* aux = pasos->primero;
    while(aux){
        aux->getDato()->imprimirLista();
        aux = aux->getSiguiente();
    }
    aux = pasos->primero;
    lista->imprimirLista();
    MainWindow w;
    w.show();

    return a.exec();
}
