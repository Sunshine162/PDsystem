#include "../../header/view/menu_file.h"
//#include "../ui_menu_file.h"
#include "ui_menu_file.h"


menuFile::menuFile(QWidget *parent) :
    QWidget(parent)
{
    //ui->setupUi(this);
    this->initUi();
    this->setupUi();
    this->setUiText();
    this->setEvent();
}

menuFile::~menuFile()
{

}

void menuFile::initUi()
{
    label_1 = new QLabel(this);
    label_2 = new QLabel(this);
    radioButton_1 = new QRadioButton(this);
    radioButton_2 = new QRadioButton(this);
    lineEdit = new QLineEdit(this);
    pushButton = new QPushButton(this);
}

void menuFile::setupUi( )
{
    label_1->setGeometry(QRect(30, 30, 51, 21));
    label_2->setGeometry(QRect(30, 60, 61, 21));
    label_2->setEnabled(false);
    radioButton_1->setGeometry(QRect(130, 30, 100, 19));
    radioButton_1->setChecked(true);
    radioButton_2->setGeometry(QRect(230, 30, 71, 19));
    lineEdit->setGeometry(QRect(130, 60, 271, 21));
    lineEdit->setEnabled(false);
    pushButton->setGeometry(QRect(400, 59, 40,23));
    pushButton->setEnabled(false);
}

void menuFile::setUiText()
{
    label_1->setText(QObject::trUtf8("输入源"));
    label_2->setText(QObject::trUtf8("打开文件"));
    radioButton_1->setText(QObject::trUtf8("摄像头"));
    radioButton_2->setText(QObject::trUtf8("外部文件"));
    pushButton->setText(QObject::trUtf8("浏览"));
}


