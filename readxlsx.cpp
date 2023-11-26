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
const int column = 11;

bool ReadXlsx::process(QString &file, QString &Error, QList <QString> &Error_db ) {
    QFileInfo filexlsx(file);
    if(!filexlsx.exists()) {
        Error = "Fail no exists";
        qDebug() << "Fail no exists";
        return false;
    }

    if(!filexlsx.isReadable())
    {
        Error = "Error: no permission to read the file";
        qDebug() << "Error: no permission to read the file";
        return false;
    }
    Document xlsxR(file);
    if (!xlsxR.load()) // load excel file
    {
        Error = "Error: file format is not xlsx";
        qDebug() << "Error: file format is not xlsx";
        return false;
    }
    QVariant mcc;
    QVariant mnc;
    int count_update = 0;
    int count_insert = 0;
    int count_insert_error = 0;
    int count_update_error = 0;
    int row = 2;
    QSqlQuery query;
    QMap <int, QVariant> qvar;
    if ( db_handler::connection(query, Error) == false ) return false;
    bool check = ReadXlsx::proverka(1,1,xlsxR);

    while(check!=false) {
        if((ReadXlsx::proverka(row,1, xlsxR) && ReadXlsx::proverka(row,2,xlsxR)) == true )
        {
            mcc = ReadXlsx::Get_value(row,1,xlsxR,Error);
            mnc = ReadXlsx::Get_value(row,2,xlsxR,Error);
        }

        db_handler::select(query,mcc,mnc, Error_db, row);

        if(query.next()) {

            for(int j = 1; j<column; j++) {

                if (ReadXlsx::proverka(row,j,xlsxR)) {
                    if(ReadXlsx::Get_value(row,j,xlsxR,Error).isValid()) {
                        qvar.insert(j, ReadXlsx::Get_value(row,j,xlsxR,Error));
                    }
                }
            }
            db_handler::update(qvar,query, Error_db, count_update_error, row);
            //qDebug() << " update " << row;
            count_update++;
            qvar.clear();
        }

        else
        {
            for(int j = 1; j<column; j++) {

                if (ReadXlsx::proverka(row,j,xlsxR)) {
                    if(ReadXlsx::Get_value(row,j,xlsxR,Error).isValid()) {
                        qvar.insert(j, ReadXlsx::Get_value(row,j,xlsxR,Error));
                    }
                }
            }
            db_handler::insert(qvar, query, Error_db, count_insert_error, row);
            //qDebug() << " insert " << row;
            count_insert++;
            qvar.clear();
        }

        row++;
        check = ReadXlsx::proverka(row,1,xlsxR);
    }

    QTextStream(&Error) << "Database filled successfully:"
                           " Insert " << (count_insert - count_insert_error) << " rows and Update "
                        << (count_update - count_update_error) << " rows. " << " Insert error " << count_insert_error <<
                           ", Update error " << count_update_error;

    qDebug() <<"Database filled unsuccessfully";
    qDebug() << " Insert " << count_insert - count_insert_error << " rows";
    qDebug() << " Update " << count_update - count_update_error << " rows";


    return true;

}


bool ReadXlsx::proverka(int row, int col, Document &xlsxR) { //checking cell is empty for file xlsx

    Cell *cell = xlsxR.cellAt(row, col);
    if(cell != NULL)
        return true;

    return false;
}

QVariant ReadXlsx::Get_value(int row, int col, Document &xlsxR, QString &Error) { //get value from file cell;


    Cell *XLSX_value = xlsxR.cellAt(row, col);
    if (XLSX_value != NULL)
    {
        QVariant var = XLSX_value->readValue();
        return var;
    }
    else
    {
        Error = "Cell is empty";
        qDebug() << "Cell is empty";
        return QVariant();
    }
}
