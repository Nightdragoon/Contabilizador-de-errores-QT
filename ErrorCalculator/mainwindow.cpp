#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QLineEdit>
#include <iostream>
#include <QMessageBox>
#include <QTableWidget>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMessageBox qm;
    qm.setText("para agregar una medicion porfavor precione el boton agregar");
    qm.exec();
    QRect rect(0,0,190,190);
    QRegion region(rect, QRegion::Ellipse);
    ui->pushButton->setMask(region);


}

MainWindow::~MainWindow()
{
    delete ui;
}
QVector<QLineEdit*> vec;
void MainWindow::on_pushButton_clicked()
{
    QLineEdit *le = new QLineEdit();

    vec.push_back(le);
    ui->verticalLayout->addWidget(le);

}



void MainWindow::on_pushButton_2_clicked()
{
    QString a = "";
    float b = 0;
    QTableWidget *table = new QTableWidget(vec.size(),3,this);
    for(QLineEdit *e : vec){
        QString at = e->text();
        b += at.toFloat();

    }
    b = b/vec.size();
    for(int i = 0; i < vec.size();i++){
        QString valAc = vec[i]->text();
        float val = valAc.toFloat();
        float errorAb = val - b;
        float errorRe = b / errorAb;
        QTableWidgetItem *item1 = new QTableWidgetItem(valAc);
        QTableWidgetItem *item2 = new QTableWidgetItem(QString::number(errorAb));
        QTableWidgetItem *item3 = new QTableWidgetItem(QString::number(errorRe));
        for(int j = 0; j < 3; j++){
        if(j == 0){table->setItem(i,j,item1);}
        if(j == 1){table->setItem(i,j,item2);}
        if(j == 2){table->setItem(i,j,item3);}

}

    }

    ui->label->setText("x1="+QString::number(b));
    ui->label->repaint();
    ui->verticalLayout_2->addWidget(table);





}






