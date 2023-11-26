#include <QCoreApplication>
#include <QDebug>
#include <QTextStream>
#include "mainwindow.h"

using namespace QXlsx;

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);
    Widget window;

    if(argc>2) {
        qDebug() << "Параметр должен быть один";
        return 1;
    }
    else if(argc==2) {

        QString file (argv[1]);
        QString Error;
        QList <QString> Error_db;
        ReadXlsx::process(file, Error, Error_db);
        return 0;
    }

    else {
        window.show();
    }
    return app.exec();

}



