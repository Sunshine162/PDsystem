#include "../../header/view/menu_detect.h"

menuDetect::menuDetect(QWidget *parent) :
    QWidget(parent)
{
    this->initUi();
    this->setupUi();
    this->setUiText();
    this->setEvent();
}

menuDetect::~menuDetect()
{
}

void menuDetect::initUi()
{
    groupBox = new QGroupBox(this);
    radioButton_1 = new QRadioButton(groupBox);
    radioButton_2 = new QRadioButton(groupBox);
    label_1 = new QLabel(groupBox);
    label_2 = new QLabel (groupBox);
    label_3 = new QLabel(groupBox);
    comboBox = new QComboBox(groupBox);
    lineEdit = new QLineEdit(groupBox);
    pushButton = new QPushButton(groupBox);
}

void menuDetect::setupUi( )
{
    this->setObjectName(QStringLiteral("tab_5"));
    groupBox->setObjectName(QStringLiteral("groupBox_5"));
    groupBox->setGeometry(QRect(30, 10, 401, 151));
    radioButton_1->setObjectName(QStringLiteral("radioButton_14"));
    radioButton_1->setGeometry(QRect(130, 40, 41, 19));
    radioButton_2->setObjectName(QStringLiteral("radioButton_11"));
    radioButton_2->setGeometry(QRect(180, 40, 41, 19));
    label_1->setObjectName(QStringLiteral("label_25"));
    label_1->setGeometry(QRect(30, 40, 71, 21));
    label_2->setObjectName(QStringLiteral("label_26"));
    label_2->setGeometry(QRect(30, 70, 51, 21));
    label_3->setObjectName(QStringLiteral("label_27"));
    label_3->setGeometry(QRect(30, 100, 61, 21));
    comboBox->setObjectName(QStringLiteral("comboBox_6"));
    comboBox->setGeometry(QRect(100, 70, 161, 21));
    lineEdit->setObjectName(QStringLiteral("lineEdit_7"));
    lineEdit->setGeometry(QRect(100, 100, 241, 21));
    pushButton->setGeometry(QRect(341,99,40,23));

    radioButton_2->setChecked(true);
    label_2->setEnabled(false);
    label_3->setEnabled(false);
    comboBox->setEnabled(false);
    lineEdit->setEnabled(false);
    pushButton->setEnabled(false);

}

void menuDetect::setUiText()
{
    groupBox->setTitle(QObject::trUtf8("使用模型"));
    radioButton_1->setText(QObject::trUtf8("是"));
    radioButton_2->setText(QObject::trUtf8("否"));
    label_1->setText(QObject::trUtf8("行人检测"));
    label_2->setText(QObject::trUtf8("分类器"));
    label_3->setText(QObject::trUtf8("加载模型"));
    comboBox->clear();
    comboBox->insertItems(0, QStringList()
                            << QObject::trUtf8("SVM")
                            << QObject::trUtf8("CNN")
                            << QObject::trUtf8("R - CNN")
                            << QObject::trUtf8("Fast R-CNN")
                            << QObject::trUtf8("Faster R-CNN")
                            << QObject::trUtf8("YOLO")
                            );
    pushButton->setText(QObject::trUtf8("浏览"));
}
