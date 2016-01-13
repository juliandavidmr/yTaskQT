#include "dialognuevatarea.h"
#include "ui_dialognuevatarea.h"

DialogNuevaTarea::DialogNuevaTarea(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogNuevaTarea)
{
    ui->setupUi(this);
}

DialogNuevaTarea::~DialogNuevaTarea()
{
    delete ui;
}
