#include "../../header/view/menu_model.h"

menuModel::menuModel(QWidget *parent) :
    QWidget(parent)
{
    this->initUi();
    this->setupUi();
    this->setUiText();
}

menuModel::~menuModel()
{
}

void menuModel::initUi()
{
    groupBox = new QGroupBox(this);
    radioButton_1 = new QRadioButton(groupBox);
    radioButton_2 = new QRadioButton(groupBox);
    label_1 = new QLabel(groupBox);
    label_2 = new QLabel(groupBox);
    label_3 = new QLabel(groupBox);
    label_4 = new QLabel(groupBox);
    label_5 = new QLabel(groupBox);
    comboBox = new QComboBox(groupBox);
    lineEdit_1 = new QLineEdit(groupBox);
    lineEdit_2 = new QLineEdit(groupBox);
    lineEdit_3 = new QLineEdit(groupBox);
    pushButton_1 = new QPushButton(groupBox);
    pushButton_2 = new QPushButton(groupBox);
    pushButton_3 = new QPushButton(groupBox);
}

void menuModel::setupUi( )
{
    this->setObjectName(QStringLiteral("tab_4"));
    groupBox->setObjectName(QStringLiteral("groupBox"));
    groupBox->setGeometry(QRect(10, 10, 431, 151));
    radioButton_1->setObjectName(QStringLiteral("radioButton_3"));
    radioButton_1->setGeometry(QRect(100, 30, 41, 19));
    radioButton_2->setObjectName(QStringLiteral("radioButton_4"));
    radioButton_2->setGeometry(QRect(150, 30, 41, 19));
    label_1->setObjectName(QStringLiteral("label_15"));
    label_1->setGeometry(QRect(30, 30, 61, 21));
    label_2->setObjectName(QStringLiteral("label_11"));
    label_2->setGeometry(QRect(260, 30, 51, 21));
    label_3->setObjectName(QStringLiteral("label_12"));
    label_3->setGeometry(QRect(30, 60, 51, 21));
    label_4->setObjectName(QStringLiteral("label_14"));
    label_4->setGeometry(QRect(30, 90, 51, 21));
    label_5->setObjectName(QStringLiteral("label_13"));
    label_5->setGeometry(QRect(30, 120, 51, 21));
    comboBox->setObjectName(QStringLiteral("comboBox_3"));
    comboBox->setGeometry(QRect(320, 30, 101, 21));
    lineEdit_1->setObjectName(QStringLiteral("lineEdit_2"));
    lineEdit_1->setGeometry(QRect(100, 60, 273, 21));
    lineEdit_2->setObjectName(QStringLiteral("lineEdit_3"));
    lineEdit_2->setGeometry(QRect(100, 90, 273, 21));
    lineEdit_3->setObjectName(QStringLiteral("lineEdit_6"));
    lineEdit_3->setGeometry(QRect(100, 120, 273, 21));

    pushButton_1->setGeometry(372,59,51,23);
    pushButton_2->setGeometry(372,89,51,23);
    pushButton_3->setGeometry(372,119,51,23);

}

void menuModel::setUiText()
{
    groupBox->setTitle(QObject::trUtf8("训练"));
    radioButton_1->setText(QObject::trUtf8("是"));
    radioButton_2->setText(QObject::trUtf8("否"));
    label_1->setText(QObject::trUtf8("训练模型"));
    label_2->setText(QObject::trUtf8("分类器"));
    label_3->setText(QObject::trUtf8("训练集"));
    label_4->setText(QObject::trUtf8("验证集"));
    label_5->setText(QObject::trUtf8("测试集"));
    pushButton_1->setText(QObject::trUtf8("浏览"));
    pushButton_2->setText(QObject::trUtf8("浏览"));
    pushButton_3->setText(QObject::trUtf8("浏览"));
    comboBox->clear();
    comboBox->insertItems(0, QStringList()
                            << QObject::trUtf8("SVM")
                            << QObject::trUtf8("CNN")
                            << QObject::trUtf8("R - CNN")
                            << QObject::trUtf8("Fast R-CNN")
                            << QObject::trUtf8("Faster R-CNN")
                            << QObject::trUtf8("YOLO")
                            );
}
