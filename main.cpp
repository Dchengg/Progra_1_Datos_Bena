#include "mainwindow.h"
#include "ListaSimple.cpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    ListaSimple<char*>* l1 = new ListaSimple<char*>;
    char* x = "diego";
    l1->insertarNodo(x);
    x = "Justin";
    l1->insertarNodo(x);
    l1->imprimirLista();
    w.show();

    return a.exec();
}
