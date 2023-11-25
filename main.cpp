#include <QCoreApplication>
#include <QDebug>
#include <QTextStream>
#include "mainwindow.h"


using namespace QXlsx;

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);
    Widget window;

    //  QString file;
    if(argc>2) {
        qDebug() << "Параметр должен быть один";
        return 1;
    }
    else if(argc==2) {

        QString file (argv[1]);
        QString Error;
        ReadXlsx::process(file, Error);
    }

    else {
        // qDebug() << "Enter the file path absolute or relative: ";
        // QTextStream cin(stdin);
        //cin >> file;
        //qDebug() << "Your file: " << file;
        window.show();

    }
    return app.exec();
    //    return 0;
    // = "/home/admin123/readxlsx/mcc-mnc.xlsx";


}



