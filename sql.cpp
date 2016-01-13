#include "sqlite.h"

sql::sql()
{
}
bool sql::conectar()
{
    if(QSqlDatabase::isDriverAvailable("QSQLITE")) //Verificamos que el driver QSQLITE este instalado.
    {
        db = QSqlDatabase::addDatabase("QSQLITE"); //Definimos que se usara SQLITE como driver
        db.setDatabaseName(QDir::homePath()+QDir::separator()+"data2.sqlite"); //Nuestra db en nuestro Home.
        bool db_ok = db.open(); //Creamos una bandera para ver si se puedo abrir la DB
        return db_ok;  //Retornamos true al metodo.
    }
    else
        qDebug() << "Driver no Disponible";
        return false;
}
