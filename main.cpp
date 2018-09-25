#include "mainwindow.h"
#include "cola.cpp"
#include "Ordenamientos.cpp"
#include <QApplication>
#include "ListaDoble.cpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    ListaDoble<int>* l1 = new ListaDoble<int>;
    int x = 2;
    l1->insertarNodo(x);
    x= 4;
    l1->insertarNodo(x);
    x= 3;
    l1->insertarNodo(x);
    x= 0;
    l1->insertarNodo(x);
    x= 1;
    l1->insertarNodo(x);
    biBurbuja(l1->primero);
    l1->imprimirLista();

    w.show();

    return a.exec();
}
