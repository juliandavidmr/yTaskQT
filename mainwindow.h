#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlQuery>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QSqlQuery query;
    void inicializar_sqlite();

private slots:
    void on_nuevatarea_clicked();

    void on_pushButton_Eliminar_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
