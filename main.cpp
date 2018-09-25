#include "mainwindow.h"
#include "cola.cpp"
#include "Ordenamientos.cpp"
#include "string.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    ListaSimple<string>* l1 = new ListaSimple<string>;
    string x = "hola";
    l1->insertarNodo(x);
    x= "arbol";
    l1->insertarNodo(x);
    x= "diego";
    l1->insertarNodo(x);
    x= "cheng";
    l1->insertarNodo(x);
    x= "sofia";
    l1->insertarNodo(x);
    biBurbuja(l1->primero);
    l1->imprimirLista();

    w.show();

    return a.exec();
}
