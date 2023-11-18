#include "readxlsx.h"
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
\
using namespace QXlsx;

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
