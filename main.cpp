#include "mainwindow.h"
#include "ListaSimple.cpp"
#include "cola.cpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Cola<char>* c1 = new Cola<char>;
    char x = 'a';
    c1->push(x);
    x= 's';
    c1->push(x);
    c1->imprimirCola();
    w.show();

    return a.exec();
}
