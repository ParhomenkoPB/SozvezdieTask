#ifndef DB_HANDLER_H
#define DB_HANDLER_H
#include <QSqlQuery>
#include <iostream>
#include <QSqlError>
#include <QMap>
#include <QQueue>

class db_handler
{
public:
    db_handler() = default;
    static QSqlQuery connection(QSqlQuery &query);
    static void update(const QMap<int,QVariant> &qvar, QSqlQuery &query);
    static void select(QSqlQuery &query);
    static void insert(const QMap<int, QVariant> &qvar, QSqlQuery &query);
    static QString ekran(QString &str);
};

#endif // DB_HANDLER_H
