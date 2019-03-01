#ifndef MENU_FILE_H
#define MENU_FILE_H

#include <QWidget>
#include <QTabWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QPushButton>

namespace Ui {
class menuFile;
}

class menuFile : public QWidget
{
    Q_OBJECT

public:
    explicit menuFile(QWidget *parent);
    ~menuFile();
    void initUi();
    void setupUi( );
    void setUiText();
    void setEvent();


private:
    QLabel *label_1;
    QLabel *label_2;
    QRadioButton *radioButton_1;
    QRadioButton *radioButton_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton;


signals:
private slots:
    void setLineEditEnable(const bool& flag);
    void chooseFile();
    void getLineEditText();
};

#endif // MENU_FILE_H
