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
    ListaSimple<int>* l1 = new ListaSimple<int>;
    int x = 4;
    l1->insertarNodo(x);
    x= 10;
    l1->insertarNodo(x);
    x= 3;
    l1->insertarNodo(x);
    x= 5;
    l1->insertarNodo(x);
    x = 1;
    l1->insertarNodo(x);
    radixsort(*l1);
    l1->imprimirLista();


    w.show();

    return a.exec();
}
