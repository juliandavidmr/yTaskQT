#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qmessagebox.h>
//ListView
#include <QStringList>
#include <QStringListModel>
#include <QAbstractItemView>
#include <QComboBox>
//SQL
#include <sqlite.h>

QStringListModel *model;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Create model
    model = new QStringListModel(this);

    // Make data
    QStringList List;
    List << "Clair de Lune\nsd" << "Reverie" << "Prelude";

    // Populate our model
    model->setStringList(List);

    // Glue model and view together
    ui->listView->setModel(model);
    ui->comboBox->setModel(model);

    // Add additional feature so that
    // we can manually modify the data in ListView
    // It may be triggered by hitting any key or double-click etc.
    ui->listView->
            setEditTriggers(QAbstractItemView::AnyKeyPressed |
                            QAbstractItemView::DoubleClicked);

    sqlite_connect();
}

MainWindow::sqlite_connect(){
    sql *s = new sql();
    if(s->conectar()){
        printf("Conectado a sqlite\n");
    } else {
        printf("No se pudo establecer la conexion con sqlite.\n");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_nuevatarea_clicked()
{
   //QMessageBox::information(this, "Mensaje información", "Bienvenido a mi primera aplicación Qt");
   // Add button clicked
   // Adding at the end

   // Get the position
   int row = model->rowCount();

   // Enable add one or more rows
   model->insertRows(row,1);

   // Get the row for Edit mode
   QModelIndex index = model->index(row);

   // Enable item selection and put it edit mode
   ui->listView->setCurrentIndex(index);
   ui->listView->edit(index);
}

void MainWindow::on_pushButton_Eliminar_clicked()
{
    // Delete button clicked
    // For delete operation,
    // we're dealing with a Model not a View
    // Get the position
    model->removeRows(ui->listView->currentIndex().row(),1);
}
