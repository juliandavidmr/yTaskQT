#include "sqlite.h"
#include <QMessageBox>
#include <iostream>

sql::sql()
{
}

bool sql::conectar()
{
    if(QSqlDatabase::isDriverAvailable("QSQLITE")) //Verificamos que el driver QSQLITE este instalado.
    {
        db = QSqlDatabase::addDatabase("QSQLITE"); //Definimos que se usara SQLITE como driver
        //db.setDatabaseName(QDir::homePath()+QDir::separator()+"data2.sqlite"); //Nuestra db en nuestro Home.
        db.setDatabaseName("./data2.sqlite"); //Nuestra db en nuestro Home.
        if (!db.open()) {
            QMessageBox::critical(0, qApp->tr("Cannot open database"),
                qApp->tr("Unable to establish a database connection.\n"
                         "This example needs SQLite support. Please read "
                         "the Qt SQL driver documentation for information how "
                         "to build it.\n\n"
                         "Click Cancel to exit."), QMessageBox::Cancel);
            conectado = false;
            return false;
        }

        QSqlQuery query;
        query.exec("CREATE TABLE `prioridad` ("
                   "`id_prioridad`	INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,"
                   "`nombre_prioridad`	TEXT NOT NULL,"
                   "`descripcion`	TEXT);"
                   );
        query.exec("CREATE TABLE `categoria` ("
                   "`id_categoria`	INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,"
                   "`nombre_categoria`	TEXT NOT NULL,"
                   "`descripcion`	TEXT);");
        query.exec("CREATE TABLE tarea ("
                   "`id_tarea`	INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,"
                   "`nombre_tarea`	TEXT NOT NULL,"
                   "`realizar_en`	TEXT,"
                   "`tags`	TEXT,"
                   "`id_categoria`	INTEGER NOT NULL,"
                   "`id_prioridad`	INTEGER NOT NULL,"
                   "`cumplido`	NUMERIC DEFAULT 0,"
                   "FOREIGN KEY(`id_categoria`) REFERENCES categoria ( id_categoria ),"
                   "FOREIGN KEY(`id_prioridad`) REFERENCES prioridad ( id_prioridad ));"
                   "");
        query.exec("CREATE INDEX `index_tarea` ON `tarea` (`id_tarea` ASC,`nombre_tarea` ASC,`realizar_en` ASC,`tags` ASC,`id_categoria` ASC,`id_prioridad` ASC);");
        query.exec("CREATE INDEX `index_categoria` ON `categoria` (`id_categoria` ASC,`nombre_categoria` ASC,`descripcion` );");
        //query.exec("insert into person values(104, 'Roberto', 'Robitaille')");

        return true;
    }
    else
        qDebug() << "Driver no Disponible";
        return false;
}

QSqlQuery sql::consultar_prioridades(){
    QSqlQuery query;
    if (sql::db.open()) {
        query.exec("SELECT * FROM prioridad;");
    }
    return query;
}
