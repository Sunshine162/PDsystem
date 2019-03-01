#include "../../header/model/md_file.h"
#include "../../header/model/encodingconvert.h"
#include "../../header/view/menu_file.h"
#include <QFileDialog>
#include <iostream>
#include <qdebug.h>
using namespace std;

void menuFile::setLineEditEnable(const bool &flag)
{

    label_2->setEnabled(flag);
    lineEdit->setEnabled(flag);
    pushButton->setEnabled(flag);
    if(flag == true){
        MdFile::setInputType(LOCAL_VIDEO);
    }else{
        MdFile::setInputType(CAMERA);
    }

}

void menuFile::getLineEditText( )
{
    QString qPath = lineEdit->text();
    string path = qstr2str(qPath);
    //string path = qPath.toStdString();   ?????为什么会乱码
    MdFile::setFilePath(path);
}

void menuFile::chooseFile()
{
    QString filename =QFileDialog::getOpenFileName(this,tr("打开视频"),".",tr("Video Files(*.avi *.mp4 *.flv *.mkv)"));
    lineEdit->setText(filename);
}

void menuFile::setEvent()
{
    connect(radioButton_2,&QRadioButton::toggled, this,&menuFile::setLineEditEnable);
    connect(pushButton, &QPushButton::clicked, this, &menuFile::chooseFile);
    connect(lineEdit, &QLineEdit::textChanged, this, &menuFile::getLineEditText);
}


