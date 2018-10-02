#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QPointF>
#include <QGraphicsItemAnimation>
#include <QTimeLine>


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


private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    void animate(QGraphicsItem* item,float x, float y);

};

#endif // MAINWINDOW_H
