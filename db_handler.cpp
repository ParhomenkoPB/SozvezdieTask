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
     //   qDebug() << "success connecting";
        query = QSqlQuery(db);
        return true;
    }
}

bool db_handler::select(QSqlQuery &query, QVariant mcc, QVariant mnc){
    QString sql_select = "SELECT mcc, mnc FROM mcc_mnc WHERE MCC=" + mcc.toString() + " AND MNC=" + mnc.toString();
    if (!query.exec(sql_select))
    {
        qDebug() << query.lastError().text();
        return false;
    }
    else {
        return true;
    }
}
QString db_handler::screening(const QString &str) { //экранирование символа '
    QString copy_str = str;
    int pos = copy_str.indexOf("\'");
    while(pos!= -1) {
       copy_str.insert(pos,'\'');
        pos = copy_str.indexOf("\'", pos+2);
        }
    return copy_str;

}
void db_handler::insert(const QMap<int, QVariant> &qvar, QSqlQuery &query){
    QString mcc = screening(qvar.value(1).toString());
    QString mnc = screening(qvar.value(2).toString());
    QString plmn = screening(qvar.value(3).toString());
    QString region = "rara";// screening(qvar.value(4).toString());
    QString country = screening(qvar.value(5).toString());
    QString iso = screening(qvar.value(6).toString());
    QString Operator = screening(qvar.value(7).toString());
    QString brand = screening(qvar.value(8).toString());
    QString tadig = screening(qvar.value(9).toString());
    QString bands = screening(qvar.value(10).toString());

    QString sql_insert = "INSERT INTO mcc_mnc (MCC, MNC, PLMN, REGION, COUNTRY, ISO, OPERATOR, BRAND, TADIG, BANDS) "
                         " VALUES (" + mcc + ", " + mnc + ", " + plmn + " , '" + region +"' , '" + country + "' , '" + iso + "' , '" + Operator + "', '" + brand + "' , '" + tadig + "' , '" + bands + "'); ";

    if (!query.exec(sql_insert))
    {
        qDebug() << query.lastError().text();
        qDebug() << sql_insert;
        qDebug() << "///////////////////////////////////////////";
    }
}

void db_handler::update(const QMap<int, QVariant> &qvar, QSqlQuery &query){
    QString mcc = screening(qvar.value(1).toString());
    QString mnc = screening(qvar.value(2).toString());
    QString plmn = screening(qvar.value(3).toString());
    QString region = screening(qvar.value(4).toString());
    QString country = screening(qvar.value(5).toString());
    QString iso = screening(qvar.value(6).toString());
    QString Operator = screening(qvar.value(7).toString());
    QString brand = screening(qvar.value(8).toString());
    QString tadig = screening(qvar.value(9).toString());
    QString bands = screening(qvar.value(10).toString());
    QString sql_update = "UPDATE mcc_mnc SET PLMN=" + plmn + ", REGION='" + region + "', COUNTRY='" + country + "', ISO='" + iso + "', OPERATOR='" + Operator + "', BRAND='" + brand + "', TADIG='" + tadig + "', BANDS='" + bands + "' WHERE MCC=" + mcc + " AND MNC=" + mnc;
    if (!query.exec(sql_update))
    {
        qDebug() << query.lastError().text();
        qDebug() << sql_update;
        qDebug() << "///////////////////////////////////////////";
    }
}


