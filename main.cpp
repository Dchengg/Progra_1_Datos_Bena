#include "mainwindow.h"
#include <QApplication>




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ListaSimple<int>* lista = new ListaSimple<int>();
    int x = 5;
    lista->insertarNodo(x);
    x = 3;
    lista->insertarNodo(x);
    x = 9;
    lista->insertarNodo(x);
    x = 1;
    lista->insertarNodo(x);
    x = 0;
    lista->insertarNodo(x);
    x = 99;
    lista->insertarNodo(x);
    Burbuja(lista);
    lista->imprimirLista();
    MainWindow w;
    w.show();

    return a.exec();
}
