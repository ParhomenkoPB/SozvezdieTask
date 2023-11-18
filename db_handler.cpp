#include "db_handler.h"
#include <QDebug>

QSqlQuery db_handler::connection(QSqlQuery &query){
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("Mybd");
    db.setUserName("user123");
    db.setPassword("12345");
    if(!db.open())
    {
        qDebug() << db.lastError().text();
    }
    else
    {
        qDebug() << "success";
        return query = QSqlQuery(db);
    }
}

void db_handler::select(QSqlQuery &query){
    QString sql_select = "SELECT mcc, mnc FROM mcc_mnc";
    if (!query.exec(sql_select))
    {
        qDebug() << query.lastError().text();
    }
}
void db_handler::insert(const QMap<int, QVariant> &qvar, QSqlQuery &query){
    QVariant mcc = qvar.value(1);
    QVariant mnc = qvar.value(2);
    QVariant plmn = qvar.value(3);
    QVariant region = qvar.value(4);
    QVariant country = qvar.value(5);
    QVariant iso = qvar.value(6);
    QVariant Operator = qvar.value(7);
    QVariant brand = qvar.value(8);
    QVariant tadig = qvar.value(9);
    QVariant band = qvar.value(10);
    QString sql_insert = "INSERT INTO mcc_mnc (MCC, MNC, PLMN, REGION, COUNTRY, ISO, OPERATOR, BRAND, TADIG, BAND) "
                         " VALUES (" + mcc.toString() + ", " + mnc.toString() + ", " + plmn.toString() + " , '" + region.toString() +"' , '" + country.toString() + "' , '" + iso.toString() + "' , '" + Operator.toString() + "', '" + brand.toString() + "' , '" + tadig.toString() + "' , '" + band.toString() + "'); ";

    if (!query.exec(sql_insert))
    {
        qDebug() << query.lastError().text();
    }
}

void db_handler::update(const QMap<int, QVariant> &qvar, QSqlQuery &query){
    QVariant mcc = qvar.value(1);
    QVariant mnc = qvar.value(2);
    QVariant plmn = qvar.value(3);
    QVariant region = qvar.value(4);
    QVariant country = qvar.value(5);
    QVariant iso = qvar.value(6);
    QVariant Operator = qvar.value(7);
    QVariant brand = qvar.value(8);
    QVariant tadig = qvar.value(9);
    QVariant band = qvar.value(10);
    QString sql_update = "UPDATE mcc_mnc SET PLMN=" + plmn.toString() + ", REGION='" + region.toString() + "', COUNTRY='" + country.toString() + "', ISO='" + iso.toString() + "', OPERATOR='" + Operator.toString() + "', BRAND='" + brand.toString() + "', TADIG='" + tadig.toString() + "', BAND='" + band.toString() + "',  WHERE MCC=" + mcc.toString() + " AND MNC=" + mnc.toString() + ");";
    if (!query.exec(sql_update))
    {
        qDebug() << query.lastError().text();
    }
}
