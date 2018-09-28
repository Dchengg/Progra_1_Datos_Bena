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
    ListaDoble<char>* l1 = new ListaDoble<char>;
    char x = 'b';
    l1->insertarNodo(x);
    x= 'c';
    l1->insertarNodo(x);
    x= 'a';
    l1->insertarNodo(x);
    x= 'z';
    l1->insertarNodo(x);
    x = 'A';
    l1->insertarNodo(x);
    heapSort(*l1);
    l1->imprimirLista();

    w.show();

    return a.exec();
}
