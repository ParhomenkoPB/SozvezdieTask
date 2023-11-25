
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//#include <QMainWindow>
#include <QtWidgets>
#include <QPushButton>
#include <QVBoxLayout>
//#include <QLayout>

#include <QFileDialog>
//#include "ui_mainwindow.h"
#include "readxlsx.h"

//namespace Ui {
//class MainWindow;
//}

class Widget : public QWidget
{
    Q_OBJECT

public:
    //explicit MainWindow(QWidget *parent = 0);
    Widget(QWidget *parent = 0);
    ~Widget();

    //private slots:
    //void on_OpenFileButton_clicked();

private:
    QPushButton *OpenFileButton;
    QPushButton *ExecButton;
    QFormLayout *vlayout;
    QLabel *label;
    QPixmap pixmap;
    QGridLayout *gridLayout;
    QHBoxLayout *ExecLayout;

    void open(QLayout *layout);

    QLineEdit *LineOpenFile;
    //QLayout *vlayout;
    //void OpenFileButton(QLayout *layout);
    //  Ui::MainWindow *ui;
    QString file_path;
private slots:
    void on_OpenFileButton_clicked();
    void on_ExecButton_clicked();
};

#endif // MAINWINDOW_H
