#include "mainwindow.h"
#include "cola.cpp"
#include "Ordenamientos.cpp"
#include "string.h"
#include <QApplication>
#include "listadoble.cpp"
#include "ListaSimple.cpp"
#include "randomizer.cpp"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    srand(time(NULL));
    ListaSimple<int>* l1 = new ListaSimple<int>;
    llenarTDA(l1,15,65,90);
    quickSort(*l1,0,l1->getTam()-1);
    l1->imprimirLista();
    w.show();

    return a.exec();
}
