#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QPointF>
#include <QGraphicsItemAnimation>
#include <QTimeLine>
#include "Ordenamientos.cpp"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void handleGenerarButton();
    void handleOrdenarButton();


private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    ListaSimple<int>* lista = new ListaSimple<int>();
    void delay();

};

#endif // MAINWINDOW_H
