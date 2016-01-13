#ifndef DIALOGNUEVATAREA_H
#define DIALOGNUEVATAREA_H

#include <QDialog>
#include <QSqlQuery>
#include <clase_tarea.h>

namespace Ui {
class DialogNuevaTarea;
}

class DialogNuevaTarea : public QDialog
{
    Q_OBJECT

public:
    explicit DialogNuevaTarea(QSqlQuery query, QWidget *parent = 0);
    ~DialogNuevaTarea();
    QSqlQuery query;

private slots:
    void on_buttonBox_accepted();

private:
    Ui::DialogNuevaTarea *ui;
};

#endif // DIALOGNUEVATAREA_H
