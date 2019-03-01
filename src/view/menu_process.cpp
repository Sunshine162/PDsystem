#include "../../header/view/menu_process.h"

menuProcess::menuProcess(QWidget *parent) :
    QWidget(parent)
{
    this->initUi();
    this->setupUi();
    this->setUiText();
}

menuProcess::~menuProcess()
{

}

void menuProcess::initUi()
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
    spinBox_1 = new QSpinBox(groupBox);
    spinBox_2 = new QSpinBox(groupBox);
    horizontalSlider = new QSlider(groupBox);

}

void menuProcess::setupUi( )
{
    this->setObjectName(QStringLiteral("tab_2"));

    groupBox->setObjectName(QStringLiteral("groupBox_3"));
    groupBox->setGeometry(QRect(20, 10, 411, 151));

    radioButton_1->setObjectName(QStringLiteral("radioButton_7"));
    radioButton_1->setGeometry(QRect(100, 20, 41, 31));

    radioButton_2->setObjectName(QStringLiteral("radioButton_8"));
    radioButton_2->setGeometry(QRect(160, 20, 41, 31));

    label_1->setObjectName(QStringLiteral("label_20"));
    label_1->setGeometry(QRect(40, 20, 51, 31));

    label_2->setObjectName(QStringLiteral("label_4"));
    label_2->setGeometry(QRect(40, 60, 31, 31));

    label_3->setObjectName(QStringLiteral("label_6"));
    label_3->setGeometry(QRect(230, 60, 51, 31));

    label_4->setObjectName(QStringLiteral("label_5"));
    label_4->setGeometry(QRect(40, 111, 31, 31));

    label_5->setObjectName(QStringLiteral("label_19"));
    label_5->setGeometry(QRect(360, 110, 41, 31));

    spinBox_1->setObjectName(QStringLiteral("spinBox_2"));
    spinBox_1->setGeometry(QRect(290, 60, 42, 31));

    spinBox_2->setObjectName(QStringLiteral("spinBox_3"));
    spinBox_2->setGeometry(QRect(360, 60, 42, 31));

    comboBox->setObjectName(QStringLiteral("comboBox"));
    comboBox->setGeometry(QRect(80, 60, 73, 31));

    horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
    horizontalSlider->setGeometry(QRect(80, 111, 261, 31));
    horizontalSlider->setOrientation(Qt::Horizontal);


}

void menuProcess::setUiText()
{
    groupBox->setTitle(QObject::trUtf8("视频预处理"));
    radioButton_1->setText(QObject::trUtf8("是"));
    radioButton_2->setText(QObject::trUtf8("否"));
    label_1->setText(QObject::trUtf8("预处理"));
    label_2->setText(QObject::trUtf8("类型"));
    label_3->setText(QObject::trUtf8("分辨率"));
    label_4->setText(QObject::trUtf8("帧率"));
    label_5->setText(QObject::trUtf8("帧/s"));
    comboBox->clear();
    comboBox->insertItems(0, QStringList()
                          << QObject::trUtf8(".mp4")
                          << QObject::trUtf8(".avi")
                          << QObject::trUtf8(".rmvb")
                          << QObject::trUtf8(".mkv")
                          );

}
