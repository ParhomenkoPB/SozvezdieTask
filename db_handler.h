
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
    static bool connection(QSqlQuery &query, QString &Error);
    static void update(const QMap<int,QVariant> &qvar, QSqlQuery &query, QString &Error);
    static bool select(QSqlQuery &query, QVariant mcc, QVariant mnc, QString &Error);
    static void insert(const QMap<int, QVariant> &qvar, QSqlQuery &query, QString &Error);
    static QString screening(const QString &str);
};

#endif // DB_HANDLER_H
