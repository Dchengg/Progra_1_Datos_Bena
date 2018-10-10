#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "randomizer.cpp"
#include <QGraphicsTextItem>
#include <QPointF>
#include <QGraphicsItemAnimation>
#include <QTimeLine>
#include <QPropertyAnimation>
#include <QTime>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
    connect(ui->generarPushButton,SIGNAL (released()), this, SLOT (handleGenerarButton()));
    connect(ui->sortPushButton,SIGNAL (released()), this, SLOT (handleOrdenarButton()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleGenerarButton(){
    scene->clear();
    llenarTDA<int>(lista, ui->tamSpinBox->value(),ui->desdeSpinBox->value(), ui->hastaSpinBox->value());
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

void MainWindow::handleOrdenarButton(){
    QString sort =  ui->sortComboBox->currentText();
    ListaDoble<ListaSimple<int>*>* pasos;
    if(sort == "Burbuja")
        pasos =  Burbuja(lista);
    else if(sort ==  "Burbuja bidireccional")
         pasos =  biBurbuja(lista);
    else if(sort ==  "Insertion")
         pasos =  insertion(lista);
    else if(sort ==  "Selection")
         pasos =  SelectionSort(lista);
    else if(sort ==  "Heapsort")
         pasos =  heapSort(*lista);
    else if(sort ==  "Radixsort")
         pasos =  radixsort(*lista);
    else if(sort ==  "Quicksort")
         pasos =  quickSort(*lista,0,lista->getTam()-1);
    else if(sort ==  "Mergesort")
         pasos =  mergeSort(*lista,0,lista->getTam()-1);
    else
         pasos =  ShellSort(lista);
    Nodo<ListaSimple<int>*>* aux = pasos->primero;
    while(aux){
        aux->getDato()->imprimirLista();
        aux = aux->getSiguiente();
    }
    aux = pasos->primero;

    while(aux){
        scene->clear();
        Nodo<int>* aux2 = aux->getDato()->primero;
        int x = 0;
        int y = 0;
        while(aux2){
            QGraphicsTextItem* nuevoElemento = new QGraphicsTextItem();
            nuevoElemento->setPlainText(QString::number(aux2->getDato()));
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
            int length  = nuevoElemento->toPlainText().size();
            x += 20*length;
            aux2 = aux2->getSiguiente();
        }
        ui->graphicsView->setScene(scene);
        ui->graphicsView->show();
        aux = aux->getSiguiente();
        delay();
    }

}

void MainWindow::delay()
{
    QTime dieTime= QTime::currentTime().addSecs(1);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
