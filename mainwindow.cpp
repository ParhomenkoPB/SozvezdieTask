//#include <QMessageBox>
#include "mainwindow.h"
//#include "ui_mainwindow.h"


//MainWindow::MainWindow(QWidget *parent) :
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    Widget::setWindowTitle("readxlsx.exe");
    Widget::setFixedSize(400,130);

    LineOpenFile = new QLineEdit();
    LineOpenFile->setReadOnly(true);

    OpenFileButton = new QPushButton;
    ExecButton = new QPushButton("Выполнить");
    label = new QLabel();

    pixmap = QPixmap("/..Button.png");
    OpenFileButton->setIcon(pixmap);
    OpenFileButton->setIconSize(QSize(30,30));

    // vlayout = new QFormLayout;
    // vlayout->addRow(LineOpenFile, OpenFileButton);
    // vlayout->setFormAlignment(Qt::AlignRight | Qt::AlignRight);
    // vlayout->setMargin(20);

    gridLayout = new QGridLayout;
    OpenFileButton->setSizePolicy(QSizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed, QSizePolicy::ToolButton));
    gridLayout->addWidget(LineOpenFile, 0, 0, Qt::Alignment());
    gridLayout->addWidget(OpenFileButton, 0, 1, Qt::Alignment());
    //gridLayout->setMargin(30);

    ExecLayout = new QHBoxLayout;
    ExecButton->setSizePolicy(QSizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed, QSizePolicy::ToolButton));
    ExecLayout->addWidget(ExecButton);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(gridLayout);
    mainLayout->addWidget(label);
    mainLayout->addLayout(ExecLayout);

    connect(OpenFileButton, &QPushButton::clicked, this, &Widget::on_OpenFileButton_clicked);
    connect(ExecButton, &QPushButton::clicked, this, &Widget::on_ExecButton_clicked);
}


//QVBoxLayout vlayout = new QVBoxLayout();
//vlayout->addWidget(OpenFileButton);
//QString str1;
// ui->setupUi(this);
//QObject::connect( ui->OpenFileButton, &QPushButton::clicked, this, &MainWindow::on_OpenFileButton_clicked );
//  setLayout(vlayout);
//vlayout->setLabelAlignment(Qt::AlignHCenter | Qt::AlignTop);
//LineOpenFile->setSizePolicy(QSizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed, QSizePolicy::ToolButton));



//  vlayout->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);
//  vlayout->setVerticalSpacing(100);
//  vlayout->setLabelAlignment(Qt::AlignLeft);


//  QHBoxLayout *dLayout = new QHBoxLayout();
// setLayout(dLayout);
// dLayout->addWidget(ExecButton);

// gridLayout->addWidget(LineOpenFile, 0, 0, Qt::Alignment(1));
// gridLayout->addWidget(OpenFileButton, 0, 1, Qt::Alignment());


// vlayout = new QFormLayout();
//vlayout->setLabelAlignment(Qt::AlignHCenter | Qt::AlignTop);
// vlayout->addRow(LineOpenFile, OpenFileButton);

//   QFormLayout *leftLayout = new QFormLayout(this);
//leftLayout->setMargin(100);
//   leftLayout->addWidget(LineOpenFile, 0, 0);
//leftLayout->addWidget(OpenFileButton, 0, 1);
//leftLayout->addWidget(label, 1, 0);

//        leftLayout->addRow(LineOpenFile, OpenFileButton);
//       leftLayout->setLabelAlignment(Qt::AlignRight | Qt::AlignRight);


//rightLayout->addStretch();






// mainLayout->setMargin(100);
// mainLayout->setSpacing(10);
// mainLayout->addStretch(1);

//mainLayout->setSpacing(10);


Widget::~Widget()
{
    // delete ui;
}

/*void Widget::open(QLayout *layout) {
  OpenFileButton = new QPushButton("Выбрать файл");
  OpenFileButton->move(10, 10);
  OpenFileButton->setGeometry(QRect(QPoint(100, 100), QSize(200, 50)));
  layout->addWidget(OpenFileButton);
}
*/
void Widget::on_OpenFileButton_clicked()
{
    QString file = QFileDialog::getOpenFileName(this, "Выбрать файл");
    //ui->label->setText(file);
    LineOpenFile->setText(file);
    file_path = file;
}

void Widget::on_ExecButton_clicked()
{
    QString Error;
    QString Success;
    bool check_out = ReadXlsx::process(file_path,Error);
    if(check_out == false) {
        QMessageBox mes;
        mes.setWindowTitle("Error!");
        mes.setStyleSheet("QLabel{min-width: 400px;}");
        mes.setStandardButtons(QMessageBox::Close);
        mes.setText(Error);
        mes.exec();
    }
    else {
        Success = Error;
        label->setText(Error);
        label->setWordWrap(true);
    }

}
//on_OpenFileButton_clicked();
/*void MainWindow::on_OpenFileButton_clicked() //кнопка выбрать
{
QString file = QFileDialog::getOpenFileName(this, "Выбрать файл");
//ui->label->setText(file);
//file_path = file;
}


void MainWindow::on_pushButton_2_clicked() //Кнопка применить
{
QString Error;
QString File;
   bool check_out = ReadXlsx::process(File,Error);
   if(check_out == false) {
       QMessageBox::about(this, "Error", Error);
   }


 //ui->label->setText(Error1);
}
*/
/*void MainWindow::on_OpenFileButton_clicked() //кнопка выбрать
{
    QPushButton *select = new QPushButton("Select File");
    layout->addWidget(select);
    connect( select, &QPushButton::clicked, this, &MainWindow::OpenFileButton );
QString file = QFileDialog::getOpenFileName(this, "Выбрать файл");
ui->label->setText(file);
file_path = file;
}

*/
