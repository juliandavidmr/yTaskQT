#ifndef SQLITE
#define SQLITE

#define SQL_H

#include <QtSql>
class sql
{
    public:
        sql();
        bool conectar();
        bool conectado;
        QSqlDatabase db;
        QSqlQuery consultar_prioridades();
};
#endif // SQL_H
