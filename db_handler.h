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
    static void update(const QMap<int,QVariant> &qvar, QSqlQuery &query, QList <QString> &Error_db, int &count_update_error, int row);
    static bool select(QSqlQuery &query, QVariant mcc, QVariant mnc, QList <QString> &Error_db, int row);
    static void insert(const QMap<int, QVariant> &qvar, QSqlQuery &query, QList <QString> &Error_db, int &count_insert_error, int row);
    static QString screening(const QString &str);
};

#endif // DB_HANDLER_H
