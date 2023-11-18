/*#include "mainwindow.h"

bool ReadXlsx::proverka(int row, int col) {
    QString fail;
Document xlsxR(fail);
    Cell *cell = xlsxR.cellAt(row, col);
    if(cell != NULL)
        return true;

    return false;
}
  QVariant ReadXlsx::Get_value( int row, int col) {
      QString fail;
Document xlsxR(fail);

    Cell *XLSX_value = xlsxR.cellAt(row, col);
       if (XLSX_value != NULL)
       {
       QVariant var = XLSX_value->readValue();
       return var;
       }
       else
       {
           qDebug() << "пустая клетка";
       }
  }

  QSqlQuery DB::connection(QSqlQuery *query){
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
  void DB::select(QSqlQuery &query){
      QString sql_select = "SELECT mcc, mnc FROM mcc_mnc";
      if (!query.exec(sql_select))
        {
            qDebug() << query.lastError().text();
        }
  }
      void DB::insert(QMap &qvar, QSqlQuery &query){
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

      void DB::update(QMap &qvar, QSqlQuery &query, QVariant mcc, QVariant mnc){
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

 //           return 0;

 void work () {
QVariant mcc;
QVariant mnc;
QSqlQuery query;
DB::connection(query);
QMap <int, QVariant> qvar;
int row = 2;
DB::select(query);
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
        for(int j = 3; j<11; j++) {

        if (ReadXlsx::proverka(row,j)) {
        if(ReadXlsx::Get_value(row,j).isValid()) {
            qvar.insert(j, ReadXlsx::Get_value(row,j).isValid());
        }
        }
        }
        DB::update(qvar,query, mcc, mnc);
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
        DB::insert(qvar, query);
        qvar.clear();


    }

row++;
check = ReadXlsx::proverka(row, 1);
}
  }
*/
