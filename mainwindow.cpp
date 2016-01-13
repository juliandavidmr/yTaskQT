#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qmessagebox.h>
//ListView
#include <QStringList>
#include <QStringListModel>
#include <QAbstractItemView>
#include <QComboBox>
#include <QTableWidgetItem>
//SQL
#include <sqlite.h>
#include <dialognuevatarea.h>

QStringListModel *model;
sql *s = new sql();
QSqlQuery query;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    inicializar_sqlite();
}

void MainWindow::inicializar_sqlite(){
    //if(s->conectar()){ }
    // ivocamos la interfaces ui y el componente, ponemos filas por defecto 1

    ui->tableWidget->setRowCount(1);

    //Añadimos 3 columnas
    ui->tableWidget->setColumnCount(3);

    //hacemos las columnas expandibles
    ui->tableWidget->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    //Añadimos un nombre a cada columna
    ui->tableWidget->setHorizontalHeaderLabels(QString("Producto;Stock;Precio").split(";"));


    //creamos una variable para el conocer numero de fila mostrada

    int i=0;
    //recorremos la consulta que realizamos antes

    query = s->consultar_prioridades();

    while (query.next()) {
        //añadimos en cada columna un dato según corresponda cada registro tiene un posición numérica en la tabla

        //producto
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(query.value(1).toString()));

        //stock
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(query.value(2).toString()));

        //precio
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(query.value(3).toString()));

        i++;
        //insertamos una nueva fila en el tablewidget

        ui->tableWidget->insertRow(i);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_nuevatarea_clicked()
{
    DialogNuevaTarea *dialog = new DialogNuevaTarea(query);
    dialog->setWindowTitle("Dialog");
    dialog->show();
}

void MainWindow::on_pushButton_Eliminar_clicked()
{

}
