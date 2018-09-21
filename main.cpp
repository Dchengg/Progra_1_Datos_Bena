#include "mainwindow.h"
#include "cola.cpp"
#include "Ordenamientos.cpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    ListaSimple<char>* l1 = new ListaSimple<char>;
    char x = 'b';
    l1->insertarNodo(x);
    x= 'a';
    l1->insertarNodo(x);
    insertion(l1->primero);
    l1->imprimirLista();

    w.show();

    return a.exec();
}
