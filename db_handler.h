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
    static bool connection(QSqlQuery &query);
    static void update(const QMap<int,QVariant> &qvar, QSqlQuery &query);
    static bool select(QSqlQuery &query, QVariant mcc, QVariant mnc);
    static void insert(const QMap<int, QVariant> &qvar, QSqlQuery &query);
    static QString screening(const QString &str);
};

#endif // DB_HANDLER_H
