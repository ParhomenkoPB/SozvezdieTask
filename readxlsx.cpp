#include "readxlsx.h"
#include "db_handler.h"
#include <QVariant>
#include <QString>

#include <QtGlobal>
#include <QCoreApplication>
#include <QtCore>
#include <QVariant>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <iostream>
#include <QSqlError>
#include <QMap>
#include <QQueue>

#include "xlsxdocument.h"
#include "xlsxchartsheet.h"
#include "xlsxcellrange.h"
#include "xlsxchart.h"
#include "xlsxrichstring.h"
#include "xlsxworkbook.h"
#include "xlsxworkbook.h"

using namespace QXlsx;

bool ReadXlsx::process(QString &file) {

    Document xlsxR(file);
    if (xlsxR.load()) // load excel file
    {
qDebug() << "sucs";
    }

    QVariant mcc;
    QVariant mnc;
    QSqlQuery query;
    db_handler::connection(query);
    QMap <int, QVariant> qvar;
    int row = 2;
    db_handler::select(query);
    bool check = ReadXlsx::proverka(1,1,xlsxR);
    //ReadXlsx
    //check = ReadXlsx::proverka(1,1);


    while(check!=false) {
        if((ReadXlsx::proverka(row,1, xlsxR) && ReadXlsx::proverka(row,1,xlsxR)) == true )
        {
            mcc = ReadXlsx::Get_value(row,1,xlsxR);
            mnc = ReadXlsx::Get_value(row,2,xlsxR);
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

                    if (ReadXlsx::proverka(row,j,xlsxR)) {
                        if(ReadXlsx::Get_value(row,j,xlsxR).isValid()) {
                            qvar.insert(j, ReadXlsx::Get_value(row,j,xlsxR));
                        }
                    }
                }
                db_handler::update(qvar,query);
                qvar.clear();
            }
        }

        else {
            for(int j = 1; j<11; j++) {

                if (ReadXlsx::proverka(row,j,xlsxR)) {
                    if(ReadXlsx::Get_value(row,j,xlsxR).isValid()) {
                        qvar.insert(j, ReadXlsx::Get_value(row,j,xlsxR));
                    }
                }
            }
            db_handler::insert(qvar, query);
            qvar.clear();


        }

        row++;
        check = ReadXlsx::proverka(row, 1, xlsxR);
    }
}


bool ReadXlsx::proverka(int row, int col, Document &xlsxR) {

    Cell *cell = xlsxR.cellAt(row, col);
    if(cell != NULL)
        return true;

    return false;
}

QVariant ReadXlsx::Get_value( int row, int col, Document &xlsxR) {


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
