#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtWidgets>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGridLayout>
//#include <QLayout>
#include <QFileDialog>
#include "readxlsx.h"


class Widget2 : public QWidget
{
    Q_OBJECT

public:
    Widget2(QWidget *parent = 0);
    ~Widget2();
    void Print_error(QString &Error_db);
    QVBoxLayout *info;

private:
    QTextEdit *log_text;

};

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    Widget2 *window2;

private:
    QPushButton *OpenInfoButton;
    QPushButton *OpenFileButton;
    QPushButton *ExecButton;
    QFormLayout *vlayout;
    QLabel *label;
    QPixmap pixmap;
    QGridLayout *gridLayout;
    QHBoxLayout *ExecLayout;
    QLineEdit *LineOpenFile;
    QString file_path;

private slots:
    void on_OpenFileButton_clicked();
    void on_ExecButton_clicked();
    void on_OpenInfoButton_clicked();
};

#endif // MAINWINDOW_H



