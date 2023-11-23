#include <QCoreApplication>
#include "mainwindow.cpp"
#include "db_handler.h"
#include "readxlsx.h"

using namespace QXlsx;

int main(int argc, char *argv[])
{
QCoreApplication app(argc, argv);
QString file = "/home/admin123/readxlsx/mcc-mnc.xlsx";
ReadXlsx::process(file);

return 0;
}


