#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ListaSimple.cpp"
#include "randomizer.cpp"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->generarPushButton,SIGNAL (released()), this, SLOT (handleGenerarButton()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleGenerarButton(){
    ListaSimple<int>* lista = new ListaSimple<int>();
    llenarTDA(lista, ui->tamSpinBox->value(),ui->desdeSpinBox->value(), ui->hastaSpinBox->value());
    lista->imprimirLista();


}
