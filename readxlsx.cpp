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
//#include <QFileInfo>
using namespace QXlsx;
const int column = 11;

bool ReadXlsx::process(QString &file) {
QFileInfo filexlsx(file);
    if(!filexlsx.exists()) {
        qDebug() << "Fail no exists";
        return false;
    }

if(!filexlsx.isReadable())
{
    qDebug() << "Error: no permission to read the file";
    return false;
}
    Document xlsxR(file);
    if (!xlsxR.load()) // load excel file
    {
qDebug() << "Error: file format is not xlsx";
return false;
    }
    QVariant mcc;
    QVariant mnc;
    int count_update = 0;
    int count_insert = 0;
    int row = 2;
    QSqlQuery query;
    QMap <int, QVariant> qvar;
    if ( db_handler::connection(query) == false ) return false;
    bool check = ReadXlsx::proverka(1,1,xlsxR);

    while(check!=false) {
        if((ReadXlsx::proverka(row,1, xlsxR) && ReadXlsx::proverka(row,2,xlsxR)) == true )
        {
            mcc = ReadXlsx::Get_value(row,1,xlsxR);
            mnc = ReadXlsx::Get_value(row,2,xlsxR);
        }

       db_handler::select(query,mcc,mnc);

           if(query.next()) {

                for(int j = 1; j<column; j++) {

                    if (ReadXlsx::proverka(row,j,xlsxR)) {
                        if(ReadXlsx::Get_value(row,j,xlsxR).isValid()) {
                            qvar.insert(j, ReadXlsx::Get_value(row,j,xlsxR));
                        }
                    }
                }
                db_handler::update(qvar,query);
                //qDebug() << " update " << row;
                count_update++;
                qvar.clear();
}

   else
           {
            for(int j = 1; j<column; j++) {

                if (ReadXlsx::proverka(row,j,xlsxR)) {
                    if(ReadXlsx::Get_value(row,j,xlsxR).isValid()) {
                        qvar.insert(j, ReadXlsx::Get_value(row,j,xlsxR));
                    }
                }
            }
            db_handler::insert(qvar, query);
            //qDebug() << " insert " << row;
            count_insert++;
            qvar.clear();
        }

        row++;
        check = ReadXlsx::proverka(row,1,xlsxR);
    }

    qDebug() <<"Database filled successfully";
    qDebug() << " Insert " << count_insert << " row";
    qDebug() << " Update " << count_update << " row";
    return true;

}


bool ReadXlsx::proverka(int row, int col, Document &xlsxR) { //checking cell is empty for file xlsx

    Cell *cell = xlsxR.cellAt(row, col);
    if(cell != NULL)
        return true;

    return false;
}

QVariant ReadXlsx::Get_value(int row, int col, Document &xlsxR) { //get value from file cell;


    Cell *XLSX_value = xlsxR.cellAt(row, col);
    if (XLSX_value != NULL)
    {
        QVariant var = XLSX_value->readValue();
        return var;
    }
    else
    {
        qDebug() << "Cell is empty";
    }
}
