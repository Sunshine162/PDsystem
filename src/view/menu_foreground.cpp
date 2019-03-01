#include "../../header/view/menu_foreground.h"

menuForeground::menuForeground(QWidget *parent) :
    QWidget(parent)
{
    this->initUi();
    this->setupUi();
    this->setUiText();
    this->setEvent();
}

menuForeground::~menuForeground()
{
}

void menuForeground::initUi()
{
    groupBox = new QGroupBox(this);
    radioButton_1 = new QRadioButton(groupBox);
    radioButton_2 = new QRadioButton(groupBox);
    label_1 = new QLabel(groupBox);
    label_2 = new QLabel(groupBox);
    label_3 = new QLabel(groupBox);
    label_4 = new QLabel(groupBox);
    label_5 = new QLabel(groupBox);
    label_6 = new QLabel(groupBox);
    label_7 = new QLabel(groupBox);
    label_8 = new QLabel(groupBox);
    label_9 = new QLabel(groupBox);
    label_10 = new QLabel(groupBox);
    comboBox = new QComboBox(groupBox);
    horizontalSlider = new QSlider(groupBox);
    spinBox_1 = new QSpinBox(groupBox);
    spinBox_2 = new QSpinBox(groupBox);
    doubleSpinBox_1 = new QDoubleSpinBox(groupBox);
    doubleSpinBox_2 = new QDoubleSpinBox(groupBox);

    label_1->setEnabled( false);
    label_2->setEnabled( false);
    label_3->setEnabled( false);
    label_4->setEnabled( false);
    label_5->setEnabled( false);
    label_6->setEnabled( false);
    label_7->setEnabled( false);
    label_8->setEnabled( false);
    label_9->setEnabled( false);
    label_10->setEnabled( false);
    comboBox->setEnabled( false);
    horizontalSlider->setEnabled( false);
    spinBox_1->setEnabled(false);
    spinBox_2->setEnabled(false);
    doubleSpinBox_1->setEnabled(false);
    doubleSpinBox_2->setEnabled(false);

}

void menuForeground::setupUi( )
{

    groupBox->setObjectName(QStringLiteral("groupBox_4"));
    groupBox->setGeometry(QRect(20, 10, 800, 161));

    radioButton_1->setObjectName(QStringLiteral("radioButton_10"));
    radioButton_1->setGeometry(QRect(160, 30, 41, 19));
    radioButton_2->setObjectName(QStringLiteral("radioButton_9"));
    radioButton_2->setGeometry(QRect(230, 30, 41, 19));
    radioButton_2->setChecked(true);

    label_1->setObjectName(QStringLiteral("label_21"));
    label_1->setGeometry(QRect(30, 30, 101, 21));
    label_2->setObjectName(QStringLiteral("label_7"));
    label_2->setGeometry(QRect(30, 70, 61, 31));
    label_3->setObjectName(QStringLiteral("label_8"));
    label_3->setGeometry(QRect(410, 70, 61, 31));
    label_4->setObjectName(QStringLiteral("label_9"));
    label_4->setGeometry(QRect(30, 120, 61, 31));
    label_5->setObjectName(QStringLiteral("label_10"));
    label_5->setGeometry(QRect(410, 120, 61, 31));
    label_6->setGeometry(QRect(505, 70, 25, 31));
    label_7->setGeometry(QRect(607, 70, 25, 31));

    label_8->setGeometry(QRect(311,120,40,31));

    label_9->setGeometry(QRect(505, 120, 25, 31));
    label_10->setGeometry(QRect(607, 120, 25, 31));

    comboBox->setObjectName(QStringLiteral("comboBox_2"));
    comboBox->setGeometry(QRect(110, 70, 211, 31));

    horizontalSlider->setObjectName(QStringLiteral("horizontalSlider_2"));
    horizontalSlider->setGeometry(QRect(110, 120, 190, 31));
    horizontalSlider->setOrientation(Qt::Horizontal);

    doubleSpinBox_1->setGeometry(QRect(531,70,70,31));
    doubleSpinBox_2->setGeometry(QRect(653,70,70,31));
    spinBox_1->setGeometry(QRect(531,120,70,31));
    spinBox_2->setGeometry(QRect(653,120,70,31));

}


void menuForeground::setUiText()
{
    groupBox->setTitle(QObject::trUtf8("寻找目标区域"));
    radioButton_1->setText(QObject::trUtf8("是"));
    radioButton_2->setText(QObject::trUtf8("否"));
    label_1->setText(QObject::trUtf8("寻找目标区域"));
    label_2->setText(QObject::trUtf8("方法"));
    label_3->setText(QObject::trUtf8("长宽比范围"));
    label_4->setText(QObject::trUtf8("灰度阈值"));
    label_5->setText(QObject::trUtf8("  面积范围"));
    label_6->setText(QObject::trUtf8("min"));
    label_7->setText(QObject::trUtf8("max"));
    label_8->setText(QObject::trUtf8("128"));
    label_9->setText(QObject::trUtf8("min"));
    label_10->setText(QObject::trUtf8("max"));

    spinBox_1->setRange(500,40000);
    spinBox_2->setRange(500,40000);
    doubleSpinBox_1->setRange(0.1, 6.0);
    doubleSpinBox_2->setRange(0.1, 6.0);
    spinBox_1->setValue(1000);
    spinBox_2->setValue(12000);
    doubleSpinBox_1->setValue(0.5);
    doubleSpinBox_2->setValue(3.0);
    spinBox_1->setSingleStep(50);
    spinBox_2->setSingleStep(50);
    doubleSpinBox_1->setSingleStep(0.1);
    doubleSpinBox_2->setSingleStep(0.1);

    horizontalSlider->setRange(0,255);
    horizontalSlider->setValue(128);

    comboBox->clear();
    comboBox->insertItems(0, QStringList()
                            << QObject::trUtf8("Background Difference")
                            << QObject::trUtf8("Visual Background Extractor")
                            << QObject::trUtf8("Gauss Background Model")
                            );

}
