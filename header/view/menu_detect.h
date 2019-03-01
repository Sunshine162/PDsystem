#ifndef MENU_DETECT_H
#define MENU_DETECT_H

#include <QWidget>

#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QPushButton>

namespace Ui {
class menuDetect;
}

class menuDetect : public QWidget
{
    Q_OBJECT

public:
    explicit menuDetect(QWidget *parent);
    ~menuDetect();
    void initUi();
    void setupUi( );
    void setUiText();

private:
    QWidget *tab_5;
    QGroupBox *groupBox;
    QLabel *label_1;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_1;
    QComboBox *comboBox;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QPushButton *pushButton;

signals:
public slots:
    void changeState(const bool& flag);
    void getComboxChecked();
    void chooseFile();
    void getLineEditText();
    void setEvent();

};

#endif // MENU_DETECT_H
