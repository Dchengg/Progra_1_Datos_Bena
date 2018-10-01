#include "mainwindow.h"
#include "cola.cpp"
#include "Ordenamientos.cpp"
#include "string.h"
#include <QApplication>
#include "ListaDoble.cpp"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    ListaSimple<int>* lista = new ListaSimple<int>;
    int dato = 10;
    lista->insertarNodo(dato);
    dato= 4;
    lista->insertarNodo(dato);
    dato= 1;
    lista->insertarNodo(dato);
    dato= 9;
    lista->insertarNodo(dato);
    dato = 0;
    lista->insertarNodo(dato);
    dato = 4;
    lista->insertarNodo(dato);

    lista->imprimirLista();
    mergeSort(*lista,0,lista->getTam()-1);
    lista->imprimirLista();

    w.show();

    return a.exec();
}
