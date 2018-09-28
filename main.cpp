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
    int x = 10;
    l1->insertarNodo(x);
    x= 4;
    l1->insertarNodo(x);
    x= 1;
    l1->insertarNodo(x);
    x= 9;
    l1->insertarNodo(x);
    x = 0;
    l1->insertarNodo(x);
    x = 4;
    l1->insertarNodo(x);
    quickSort(*l1,0,l1->getTam()-1);
    l1->imprimirLista();

    w.show();

    return a.exec();
}
