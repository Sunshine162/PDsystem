#ifndef MENU_PROCESS_H
#define MENU_PROCESS_H

#include <QWidget>
#include <QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>


namespace Ui {
class menuProcess;
}

class menuProcess : public QWidget
{
    Q_OBJECT

public:
    explicit menuProcess(QWidget *parent);
    ~menuProcess();
    void initUi();
    void setupUi( );
    void setUiText();

private:
    QGroupBox *groupBox;
    QRadioButton *radioButton_1;
    QRadioButton *radioButton_2;
    QLabel *label_1;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QSpinBox *spinBox_1;
    QSpinBox *spinBox_2;
    QComboBox *comboBox;
    QSlider *horizontalSlider;
};


#endif // MENU_PROCESS_H
