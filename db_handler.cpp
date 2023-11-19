#include "db_handler.h"
#include <QDebug>

bool db_handler::connection(QSqlQuery &query){
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("Mydb");
    db.setUserName("user123");
    db.setPassword("12345");
    if(!db.open())
    {
        qDebug() << db.lastError().text();
        return false;
    }
    else
    {
        qDebug() << "success";
        query = QSqlQuery(db);
        return true;
    }
}

bool db_handler::select(QSqlQuery &query, QVariant mcc, QVariant mnc){
  //  mcc.convert(qMetaTypeId<int>());
  //  mnc.convert(qMetaTypeId<int>());
    QString sql_select = "SELECT mcc, mnc FROM mcc_mnc";// WHERE MCC=" + mcc.toString() + " AND MNC=" + mnc.toString();
    if (!query.exec(sql_select))
    {
        qDebug() << query.lastError().text();
        return false;
    }
    else {
        return true;
    }
}
QString db_handler::ekran(const QString &str) {
    //for(int i = 1; i<11;
    QString copy_str = str;
    int pos = copy_str.indexOf("\'");
    while(pos!= -1) {
       copy_str.insert(pos,'\'');
        pos = copy_str.indexOf("\'", pos+2);
        }
    return copy_str;

}
void db_handler::insert(const QMap<int, QVariant> &qvar, QSqlQuery &query){
    QString mcc = ekran(qvar.value(1).toString());
    QString mnc = ekran(qvar.value(2).toString());
    QString plmn = ekran(qvar.value(3).toString());
    QString region = "rara";// ekran(qvar.value(4).toString());
    QString country = ekran(qvar.value(5).toString());
    QString iso = ekran(qvar.value(6).toString());
    QString Operator =  ekran(qvar.value(7).toString());
    QString brand = ekran(qvar.value(8).toString());
    QString tadig = ekran(qvar.value(9).toString());
    QString band = ekran(qvar.value(10).toString());

    QString sql_insert = "INSERT INTO mcc_mnc (MCC, MNC, PLMN, REGION, COUNTRY, ISO, OPERATOR, BRAND, TADIG, BAND) "
                         " VALUES (" + mcc + ", " + mnc + ", " + plmn + " , '" + region +"' , '" + country + "' , '" + iso + "' , '" + Operator + "', '" + brand + "' , '" + tadig + "' , '" + band + "'); ";

    if (!query.exec(sql_insert))
    {
        qDebug() << query.lastError().text();
        qDebug() << sql_insert;
        qDebug() << "///////////////////////////////////////////";
    }
}

void db_handler::update(const QMap<int, QVariant> &qvar, QSqlQuery &query){
    QString mcc = ekran(qvar.value(1).toString());
    QString mnc = ekran(qvar.value(2).toString());
    QString plmn = ekran(qvar.value(3).toString());
    QString region = ekran(qvar.value(4).toString());
    QString country = ekran(qvar.value(5).toString());
    QString iso = ekran(qvar.value(6).toString());
    QString Operator = ekran(qvar.value(7).toString());
    QString brand = ekran(qvar.value(8).toString());
    QString tadig = ekran(qvar.value(9).toString());
    QString band = ekran(qvar.value(10).toString());
    QString sql_update = "UPDATE mcc_mnc SET PLMN=" + plmn + ", REGION='" + region + "', COUNTRY='" + country + "', ISO='" + iso + "', OPERATOR='" + Operator + "', BRAND='" + brand + "', TADIG='" + tadig + "', BAND='" + band + "' WHERE MCC=" + mcc + " AND MNC=" + mnc;
    if (!query.exec(sql_update))
    {
        qDebug() << query.lastError().text();
        qDebug() << sql_update;
        qDebug() << "///////////////////////////////////////////";
    }
}


