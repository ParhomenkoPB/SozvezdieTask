#ifndef READXLSX_H
#define READXLSX_H
#include <QVariant>
#include <QString>
#include "xlsxdocument.h"

class ReadXlsx
{
public:
    ReadXlsx() = default;

static QVariant Get_value(int row, int col, QXlsx::Document &xlsxR);
static bool proverka(int row, int col, QXlsx::Document &xlsxR);
static bool process(QString &failname);
};

#endif // READXLSX_H
