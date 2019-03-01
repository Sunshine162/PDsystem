#ifndef MENU_FOREGROUND_H
#define MENU_FOREGROUND_H

#include <QWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QDoubleSpinBox>
#include <QSpinBox>

namespace Ui {
class menuForeground;
}

class menuForeground : public QWidget
{
    Q_OBJECT

public:
    explicit menuForeground(QWidget *parent);
    ~menuForeground();
    void initUi();
    void setupUi( );
    void setUiText();
    void setEvent();

private:
    QGroupBox *groupBox;
    QRadioButton *radioButton_1;
    QRadioButton *radioButton_2;
    QLabel *label_1;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QComboBox *comboBox;
    QSlider *horizontalSlider;
    QDoubleSpinBox *doubleSpinBox_1;
    QDoubleSpinBox *doubleSpinBox_2;
    QSpinBox *spinBox_1;
    QSpinBox *spinBox_2;

signals:
public slots:
    void changeState(bool flag);
    void getComboxChecked();
    void getHsValue();
    void getSb1Value(int);
    void getSb2Value(int);
    void getDSb1Value(double);
    void getDSb2Value(double);

};

#endif // MENU_FOREGROUND_H
