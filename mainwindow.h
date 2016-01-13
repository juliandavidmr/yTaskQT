#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_nuevatarea_clicked();

    void on_pushButton_Eliminar_clicked();

    void on_pushButton_editar_clicked();

    void sqlite_connect();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
