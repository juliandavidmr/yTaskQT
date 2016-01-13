#include "dialognuevatarea.h"
#include "ui_dialognuevatarea.h"
#include <clase_tarea.h>
#include <QSqlQuery>

DialogNuevaTarea::DialogNuevaTarea(QSqlQuery query, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogNuevaTarea)
{
    ui->setupUi(this);
    this->query = query;
}

DialogNuevaTarea::~DialogNuevaTarea()
{
    delete ui;
}

void DialogNuevaTarea::on_buttonBox_accepted()
{
    clase_tarea tarea;
    tarea.nombretarea = ui->lineEdit_nombretarea->text();
    tarea.fecha = ui->dateTimeEdit_realizaren->dateTime();
    tarea.tags = ui->lineEdit_tags->text();
    tarea.categoria = ui->comboBox_categoria->currentText().split(" ")[0].toInt();
    tarea.prioridad = ui->comboBox_prioridad->currentText().split(" ")[0].toInt();

    query.exec("");
}
