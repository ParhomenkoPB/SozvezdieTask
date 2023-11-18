
/*#pragma once
#include <QtGlobal>
include <QCoreApplication>
#include <QtCore>
#include <QVariant>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <iostream>
#include <QSqlError>
#include <QMap>
#include <QQueue>
//using namespace std;

// [0] include QXlsx headers
#include "xlsxdocument.h"
#include "xlsxchartsheet.h"
#include "xlsxcellrange.h"
#include "xlsxchart.h"
#include "xlsxrichstring.h"
#include "xlsxworkbook.h"
#include "xlsxworkbook.h"

using namespace QXlsx;
class readxlsx {
public:
    Document xlsxR(QString &fail);
Cell *cell;
}
*/

//#include <QtGlobal>
#include <QCoreApplication>
#include "mainwindow.cpp"
#include "db_handler.h"
#include "readxlsx.h"
/*


using namespace QXlsx;*/


void work () {
QVariant mcc;
QVariant mnc;
QSqlQuery query;
db_handler::connection(query);
QMap <int, QVariant> qvar;
int row = 2;
db_handler::select(query);
bool check = ReadXlsx::proverka(1,1);
//ReadXlsx
//check = ReadXlsx::proverka(1,1);


while(check!=false) {
    if((ReadXlsx::proverka(row,1) && ReadXlsx::proverka(row,1)) == true )
    {
     mcc = ReadXlsx::Get_value(row,1);
     mnc = ReadXlsx::Get_value(row,2);
}
    //if (mnc_value != NULL && mcc_value != NULL && plmn_value != NULL) {
    //mcc = mcc_value->readValue();
    //mnc = mnc_value->readValue();
    //plmn = plmn_value->readValue();

    if(query.next()){
    int mcc_db = query.value(0).toInt();
    int mnc_db = query.value(1).toInt();
    if( (mcc_db == mcc) && (mnc_db == mnc) )
{
        for(int j = 1; j<11; j++) {

        if (ReadXlsx::proverka(row,j)) {
        if(ReadXlsx::Get_value(row,j).isValid()) {
            qvar.insert(j, ReadXlsx::Get_value(row,j).isValid());
        }
        }
        }
        db_handler::update(qvar,query);
              qvar.clear();
}
}

    else {
        for(int j = 1; j<11; j++) {

        if (ReadXlsx::proverka(row,j)) {
        if(ReadXlsx::Get_value(row,j).isValid()) {
        qvar.insert(j, ReadXlsx::Get_value(row,j).isValid());
        }
        }
        }
        db_handler::insert(qvar, query);
        qvar.clear();


    }

row++;
check = ReadXlsx::proverka(row, 1);
}
  }

int main(int argc, char *argv[])
{

QCoreApplication app(argc, argv);
while(true) {
    work();
}
/*
QMap <int, QString> parametr;
parametr[1] = "MCC";
parametr[2] = "MNC";
parametr[3] = "PLMN";
parametr[4] = "REGION";
parametr[5] = "COUNTRY";
parametr[6] = "ISO";
parametr[7] = "OPERATOR";
parametr[8] = "BRAND";
parametr[9] = "TADIG";
parametr[10] = "BANDS";

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
}
QSqlQuery query = QSqlQuery(db);

//if (!query.exec("select * from mcc-mnc")) {
//    qDebug() << query.lastError().text();
    //return;
//}


/*----------------
int row = 5; int col = 6;

// [1] Writing excel file(*.xlsx)
QXlsx::Document xlsxW;
QVariant writeValue = 1;//QString("Hello Qt!");
xlsxW.write(row, col, writeValue); // write "Hello Qt!" to cell(A,1).
xlsxW.saveAs("Test.xlsx"); // save the document as 'Test.xlsx'
// [2] Reading excel file(*.xlsx)
*///Document xlsxR("mcc-mnc.xlsx");//mcc-mnc.xlsx");
//if (xlsxR.load()) // load excel file
//{

   // for(row = 1; row<20;row++) {
      //  for(col = 1; col<11;col++) {







/*
Cell *cell; //= xlsxR.cellAt(row, col); // get cell pointer.
Cell *mcc_value;
Cell *mnc_value;
QMap <int, QVariant> qvar;
QVariant plmn;
QVariant mcc;
QVariant mnc;
int count_endrow = 0;
int row = 2;

query.exec("SELECT mcc, mnc FROM mcc_mnc");
cell = xlsxR.cellAt(row,1);
while(cell != NULL) {
    qDebug() << row;
    //query.next();


//if (cell != NULL)
      mcc_value = xlsxR.cellAt(row, 1);
      mnc_value = xlsxR.cellAt(row, 2);
     Cell *plmn_value = xlsxR.cellAt(row, 3);
      if (mnc_value != NULL && mcc_value != NULL && plmn_value != NULL) {
      mcc = mcc_value->readValue();
      mnc = mnc_value->readValue();
      plmn = plmn_value->readValue();
}
     // if(mcc.canConvert<int>() && mnc.canConvert<int>() && plmn.canConvert<int>()){
   //   mcc.convert(qMetaTypeId<int>());
     // mnc.convert(qMetaTypeId<int>());
     // plmn.convert(qMetaTypeId<int>());
     // }

     // else {
     //     qDebug() << "тут";
     //     return 1;
     // }
      if(query.next()){
      int mcc_db = query.value(0).toInt();
      int mnc_db = query.value(1).toInt();
     // qDebug() << "тут"


      if( (mcc_db == mcc) && (mnc_db == mnc) )
{
          for(int j = 3; j<11; j++) {

          cell = xlsxR.cellAt(row, j);
          if (cell != NULL) {
          QVariant value = cell->readValue();
          if(value.isValid()) {
          qvar.insert(j, value);
          }
          }
          }
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
query.exec(sql_update);
                qvar.clear();
}
}
      else {


          for(int j = 1; j<11; j++) {

          cell = xlsxR.cellAt(row, j);
          if (cell != NULL) {
          QVariant value = cell->readValue();
          if(value.isValid()) {
          qvar.insert(j, value);
          }
          }
          }

        //query.prepare("INSERT INTO mcc_mnc (MCC, MNC, PLMN, REGION, COUNTRY, ISO, OPERATOR, BRAND, TADIG, BAND) " "VALUES (:MCC, :MNC, :PLMN, :REGION, :COUNTRY, :ISO, :OPERATOR, :BRAND, :TADIG, :BAND)");
         QVariant mcc = qvar.value(1);
         //mcc.convert(qMetaTypeId<int>());
         //query.bindValue(":MCC", mcc);
         QVariant mnc = qvar.value(2);
        // mnc.convert(qMetaTypeId<int>());
        //  query.bindValue(":MNC", mnc);
          QVariant plmn = qvar.value(3);
        // plmn.convert(qMetaTypeId<int>());
         //query.bindValue(":PLMN", plmn);
          QVariant region = qvar.value(4);
         // query.bindValue(":REGION", region);
          QVariant country = qvar.value(5);
        //  query.bindValue(":COUNTRY", country);
          QVariant iso = qvar.value(6);
        //  query.bindValue(":ISO", iso);
          QVariant Operator = qvar.value(7);
        // query.bindValue(":OPERATOR", Operator);
          QVariant brand = qvar.value(8);
        //  query.bindValue(":BRAND", brand);
          QVariant tadig = qvar.value(9);
        //  query.bindValue(":TADIG", tadig);
          QVariant band = qvar.value(10);
        //  query.bindValue(":BAND", band);
        //  query.exec();


       //   "VALUES ("mcc.toString()+, mnc, plmn, region, country, iso, Operator, brand, tadig, band)");
                  QString sql_insert = "INSERT INTO mcc_mnc (MCC, MNC, PLMN, REGION, COUNTRY, ISO, OPERATOR, BRAND, TADIG, BAND) "
                 " VALUES (" + mcc.toString() + ", " + mnc.toString() + ", " + plmn.toString() + " , '" + region.toString() +"' , '" + country.toString() + "' , '" + iso.toString() + "' , '" + Operator.toString() + "', '" + brand.toString() + "' , '" + tadig.toString() + "' , '" + band.toString() + "'); ";
//qDebug() << sql_insert;
              //    QString sql_update = "UPDATE mcc_mnc SET mcc=" + mcc.toString() + ", mnc=" + mnc.toString() + ", plmn=" + plmn.toString() + ", region='" + region.toString() + "', country='" + country.toString() + "','" + iso.toString() + "', WHERE mcc=" + mcc.toString() + " AND mnc=" + mnc.toString() + ";";
query.exec(sql_insert);


                //  if(!query.exec(sql_insert)){
                  //    QSqlError error = query.lastError();
                    //  qDebug() << error.text();
                  //}
                  qvar.clear();
      }

     row++;
     cell = xlsxR.cellAt(row, 1);


}
return 0;
}
*/

return 0;
}
