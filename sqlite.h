#ifndef SQLITE
#define SQLITE

#define SQL_H

#include <QtSql>
class sql
{
    public:
        sql();
        bool conectar();
        QSqlDatabase db;
};
#endif // SQL_H
