#include "../../header/model/md_foreground.h"
#include "../../header/model/encodingconvert.h"
#include "../../header/view/menu_foreground.h"
#include <iostream>
#include <string.h>
#include <qdebug.h>
using namespace std;


void menuForeground::changeState(bool flag){
    label_1->setEnabled(flag);
    label_2->setEnabled(flag);
    label_3->setEnabled(flag);
    label_4->setEnabled(flag);
    label_5->setEnabled(flag);
    label_6->setEnabled(flag);
    label_7->setEnabled(flag);
    label_8->setEnabled(flag);
    label_9->setEnabled(flag);
    label_10->setEnabled(flag);
    comboBox->setEnabled(flag);
    horizontalSlider->setEnabled(flag);
    spinBox_1->setEnabled(flag);
    spinBox_2->setEnabled(flag);
    doubleSpinBox_1->setEnabled(flag);
    doubleSpinBox_2->setEnabled(flag);

    MdForeground::setIsGetROI(flag);
}

void menuForeground::getComboxChecked(){
    qDebug() << comboBox->currentText() << endl;
    string method = qstr2str(comboBox->currentText());
    MdForeground::setMethod(method);
}

void menuForeground::getHsValue(){
    int num = horizontalSlider->value();
    QString str = QString("%1").arg(num);
    label_8->setText(str);

    MdForeground::setGrayThreshold(num);
}


void menuForeground::getSb1Value(int num){
    int num2 = spinBox_2->value();
    if(num >= num2){
        num = num2-50;
        spinBox_1->setValue(num);
    }
    qDebug() << num << endl;

    MdForeground::setMinArea(num);
}

void menuForeground::getSb2Value(int num){
    int num1 = spinBox_1->value();
    if(num <= num1){
        num = num1+50;
        spinBox_2->setValue(num);
    }
    qDebug() << num << endl;

    MdForeground::setMaxArea(num);
}

void menuForeground::getDSb1Value(double num){
    double num2 = doubleSpinBox_2->value();
    if(num >= num2){
        num = num2-0.1;
        doubleSpinBox_1->setValue(num);
    }
    qDebug() << num << endl;

    MdForeground::setMinAspectRatio(num);
}

void menuForeground::getDSb2Value(double num){
    double num1 = doubleSpinBox_1->value();
    if(num <= num1){
        num = num1+0.1;
        doubleSpinBox_2->setValue(num);
    }
    qDebug() << num << endl;

    MdForeground::setMaxAspectRatio(num);
}

void menuForeground::setEvent(){

    connect(horizontalSlider, &QSlider::valueChanged, this, &menuForeground::getHsValue);
    connect(comboBox, &QComboBox::currentTextChanged, this, menuForeground::getComboxChecked);
    connect(radioButton_1, &QRadioButton::toggled, this, &menuForeground::changeState);
    connect(spinBox_1, SIGNAL(valueChanged(int)),this, SLOT(getSb1Value(int)));
    connect(spinBox_2, SIGNAL(valueChanged(int)),this, SLOT(getSb2Value(int)));
    connect(doubleSpinBox_1, SIGNAL(valueChanged(double)),this, SLOT(getDSb1Value(double)));
    connect(doubleSpinBox_2, SIGNAL(valueChanged(double)),this, SLOT(getDSb2Value(double)));
}
