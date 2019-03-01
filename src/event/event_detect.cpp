#include "../../header/model/md_detect.h"
#include "../../header/model/encodingconvert.h"
#include "../../header/view/menu_detect.h"
#include <QFileDialog>
#include <qdebug.h>

void menuDetect::changeState(const bool &flag)
{
    label_2->setEnabled(flag);
    label_3->setEnabled(flag);
    comboBox->setEnabled(flag);
    lineEdit->setEnabled(flag);
    pushButton->setEnabled(flag);

    MdDetect::setIsDetect(flag);
}

void menuDetect::getLineEditText( )
{
    QString qPath = lineEdit->text();
    string path = qstr2str(qPath);
    MdDetect::setModelPath(path);
}

void menuDetect::chooseFile()
{
    QString filename =QFileDialog::getOpenFileName(this,tr("选择分类器文件"),".",tr("分类器文件(*.xml)"));
    lineEdit->setText(filename);
}

void menuDetect::getComboxChecked(){
    string classifier = qstr2str(comboBox->currentText());
    MdDetect::setClassifier(classifier);
}

void menuDetect::setEvent()
{
    connect(radioButton_1,&QRadioButton::toggled, this,&menuDetect::changeState);
    connect(pushButton, &QPushButton::clicked, this, &menuDetect::chooseFile);
    connect(lineEdit, &QLineEdit::textChanged, this, &menuDetect::getLineEditText);
}
