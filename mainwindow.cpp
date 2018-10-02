#include "mainwindow.h"
#include "ui_mainwindow.h"
<<<<<<< HEAD
#include "ListaSimple.cpp"
#include "randomizer.cpp"
#include <QGraphicsTextItem>
#include <QPointF>
#include <QGraphicsItemAnimation>
#include <QTimeLine>
#include <QPropertyAnimation>
=======
>>>>>>> c52e9396f8d7e19b0dacd6e7ecbaad9d1c4e028e

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
<<<<<<< HEAD

    scene = new QGraphicsScene();
    connect(ui->generarPushButton,SIGNAL (released()), this, SLOT (handleGenerarButton()));

=======
>>>>>>> c52e9396f8d7e19b0dacd6e7ecbaad9d1c4e028e
}

MainWindow::~MainWindow()
{
    delete ui;
}
<<<<<<< HEAD

void MainWindow::handleGenerarButton(){
    scene->clear();
    ListaSimple<int>* lista = new ListaSimple<int>();
    llenarTDA(lista, ui->tamSpinBox->value(),ui->desdeSpinBox->value(), ui->hastaSpinBox->value());
    lista->imprimirLista();
    Nodo<int>* aux = lista->primero;
    int x = 0;
    int y = 0;
    while(aux){
        QGraphicsTextItem* nuevoElemento = new QGraphicsTextItem();
        nuevoElemento->setPlainText(QString::number(aux->getDato()));
        QFont font = nuevoElemento->font();
        font.setPointSize(20);
        font.setBold(true);
        nuevoElemento->setFont(font);
        nuevoElemento->adjustSize();
        nuevoElemento->setDefaultTextColor("QGraphicsTextItem { background-color : blue; color : black; }");
        QPointF point = QPointF(x,y);
        QPointF pointItem = nuevoElemento->mapFromScene(point);
        nuevoElemento->setPos(pointItem);
        scene->addItem(nuevoElemento);
        aux = aux->getSiguiente();
        int length  = nuevoElemento->toPlainText().size();
        x += 20*length;
    }
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();



}

=======
>>>>>>> c52e9396f8d7e19b0dacd6e7ecbaad9d1c4e028e
