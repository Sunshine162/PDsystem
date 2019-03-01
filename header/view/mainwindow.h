#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "menu_file.h"
#include "menu_process.h"
#include "menu_foreground.h"
#include "menu_model.h"
#include "menu_detect.h"

#include <QMainWindow>
#include <QTabWidget>
#include <QApplication>
#include <QScrollArea>
#include <QPushButton>
#include <QLabel>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void initUi();
    void setupUi();
    void setUiText();
    static QLabel *videoLabel;

public slots:
    void start();
    void close();
    void reset();
    void pause();

private:
    Ui::MainWindow *ui;
    QTabWidget *tabWidget;
    QWidget *centralWidget;
    QScrollArea *scrollArea;
    QWidget *widget;
    QStatusBar *statusBar;

    QPushButton *pushButton_1;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    menuFile *menu_fi;
    menuProcess *menu_pr;
    menuForeground *menu_fo;
    menuModel *menu_mo;
    menuDetect *menu_de;
};

#endif // MAINWINDOW_H
