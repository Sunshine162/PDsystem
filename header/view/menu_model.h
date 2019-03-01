#ifndef MENU_MODEL_H
#define MENU_MODEL_H

#include <QWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QPushButton>



namespace Ui {
class menuModel;
}

class menuModel : public QWidget
{
    Q_OBJECT

public:
    explicit menuModel(QWidget *parent);
    ~menuModel();
    void initUi();
    void setupUi( );
    void setUiText();

private:
    QGroupBox *groupBox;
    QLabel *label_5;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_1;
    QComboBox *comboBox;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_2;
    QLabel *label_1;
    QRadioButton *radioButton_1;
    QRadioButton *radioButton_2;
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

};


#endif // MENU_MODEL_H
