#include <QStyle>
#include <QDesktopWidget>
#include "mainwindow.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    Widget::setWindowTitle("readxlsx.exe");
    Widget::setFixedSize(400,130);
    QDesktopWidget desktop;
    QRect rect = desktop.availableGeometry(this);
    QPoint center = rect.center();
    int x = center.x() - (width()/2);
    int y = center.y() - (height()/2);
    center.setX(x);
    center.setY(y);
    move(center);
    window2 = new Widget2;
    window2->hide();
    LineOpenFile = new QLineEdit();
    LineOpenFile->setReadOnly(true);

    OpenInfoButton = new QPushButton("Журнал ошибок");
    OpenFileButton = new QPushButton;
    ExecButton = new QPushButton("Выполнить");
    label = new QLabel();

    pixmap = QPixmap(":/image/button.png");
    OpenFileButton->setIcon(pixmap);
    OpenFileButton->setIconSize(QSize(40,22));

    gridLayout = new QGridLayout;
    OpenInfoButton->setSizePolicy(QSizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed, QSizePolicy::ToolButton));
    OpenFileButton->setSizePolicy(QSizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed, QSizePolicy::ToolButton));
    gridLayout->addWidget(LineOpenFile, 0, 0, Qt::Alignment());
    gridLayout->addWidget(OpenFileButton, 0, 1, Qt::Alignment());

    ExecLayout = new QHBoxLayout;
    ExecButton->setSizePolicy(QSizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed, QSizePolicy::ToolButton));
    ExecLayout->addWidget(OpenInfoButton);
    ExecLayout->addWidget(ExecButton);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(gridLayout);
    mainLayout->addWidget(label);
    mainLayout->addLayout(ExecLayout);


    connect(OpenFileButton, &QPushButton::clicked, this, &Widget::on_OpenFileButton_clicked);
    connect(ExecButton, &QPushButton::clicked, this, &Widget::on_ExecButton_clicked);
    connect(OpenInfoButton, &QPushButton::clicked, this, &Widget::on_OpenInfoButton_clicked);
}

Widget::~Widget()
{
}

Widget2::Widget2(QWidget *parent)
    : QWidget(parent)
{
    Widget2::setWindowTitle("Information about error");
    QDesktopWidget desktop;
    QRect rect = desktop.availableGeometry(this);
    QPoint center = rect.center();
    int x = center.x() - (width()/2);
    int y = center.y() - (height()/2);
    center.setX(x);
    center.setY(y);
    move(center);
    log_text = new QTextEdit;
    log_text->setReadOnly(true);
    QVBoxLayout *info = new QVBoxLayout(this);
    info->addWidget(log_text);
}


Widget2::~Widget2()
{
}

void Widget2::Print_error(QString &Error_dB) {

    log_text->insertPlainText(Error_dB + '\n');

}


void Widget::on_OpenInfoButton_clicked()
{

    window2->show();

}


void Widget::on_OpenFileButton_clicked()
{
    QString file = QFileDialog::getOpenFileName(this, "Выбрать файл");
    LineOpenFile->setText(file);
    file_path = file;

}

void Widget::on_ExecButton_clicked()
{
    QString Error;
    QList <QString> Error_db;
    QString Success;
    QMessageBox mes;
    mes.setWindowTitle("Error!");
    //mes.setFixedSize(200,200);
    mes.setStyleSheet("QLabel{min-width: 400px;}");
    mes.setStandardButtons(QMessageBox::Close);
    bool check_out = ReadXlsx::process(file_path,Error, Error_db);
    if(check_out == false) {
        mes.setText(Error);
        mes.exec();
        window2->Print_error(Error);
    }
    else if(!Error_db.empty()) {
        label->setText(Error);
        label->setWordWrap(true);
        QString Error_dB;
        for (int i = 0; i<Error_db.size(); i++) {
            Error_dB += Error_db.at(i) + QString("\n");
        }

        window2->Print_error(Error_dB);

    }
    else {
        Success = Error;
        label->setText(Success);
        label->setWordWrap(true);
    }

}
