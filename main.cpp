#include <QCoreApplication>
#include <QDebug>
#include <QTextStream>
#include "mainwindow.cpp"
#include "db_handler.h"
#include "readxlsx.h"


using namespace QXlsx;

int main(int argc, char *argv[])
{
QCoreApplication app(argc, argv);
QString file;   // = "/home/admin123/readxlsx/mcc-mnc.xlsx";
qDebug() << "Enter the file path absolute or relative: ";
QTextStream cin(stdin);
cin >> file;
qDebug() << "Your file: " << file;
ReadXlsx::process(file);

return 0;
}


