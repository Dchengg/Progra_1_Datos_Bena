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
    ListaSimple<int>* l1sta = new ListaSimple<int>;
    int dato = 10;
    l1sta->insertarNodo(dato);
    dato= 4;
    l1sta->insertarNodo(dato);
    dato= 1;
    l1sta->insertarNodo(dato);
    dato= 9;
    l1sta->insertarNodo(dato);
    dato = 0;
    l1sta->insertarNodo(dato);
    dato = 4;
    l1sta->insertarNodo(dato);

    l1sta->imprimirLista();
    SelectionSort(l1sta->primero);
    l1sta->imprimirLista();

    w.show();

    return a.exec();
}
