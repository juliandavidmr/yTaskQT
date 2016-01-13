#ifndef DIALOGNUEVATAREA_H
#define DIALOGNUEVATAREA_H

#include <QDialog>

namespace Ui {
class DialogNuevaTarea;
}

class DialogNuevaTarea : public QDialog
{
    Q_OBJECT

public:
    explicit DialogNuevaTarea(QWidget *parent = 0);
    ~DialogNuevaTarea();

private:
    Ui::DialogNuevaTarea *ui;
};

#endif // DIALOGNUEVATAREA_H
