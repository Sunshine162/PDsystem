#include "../../header/view/mainwindow.h"
//#include "../ui_mainwindow.h"
#include "ui_mainwindow.h"

QLabel* MainWindow::videoLabel = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->initUi();
    this->setupUi();
    this->setUiText();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initUi()
{
    centralWidget = new QWidget(this);
    scrollArea = new QScrollArea(centralWidget);
    widget = new QWidget(centralWidget);
    pushButton_1 = new QPushButton(widget);
    pushButton_2 = new QPushButton(widget);
    pushButton_3 = new QPushButton(widget);
    pushButton_4 = new QPushButton(widget);
    tabWidget = new QTabWidget(widget);
    menu_fi = new menuFile(tabWidget);
    menu_pr = new menuProcess(tabWidget);
    menu_fo = new menuForeground(tabWidget);
    menu_mo = new menuModel(tabWidget);
    menu_de = new menuDetect(tabWidget);
    statusBar = new QStatusBar(centralWidget);
    videoLabel = new QLabel(scrollArea);
}

void MainWindow::setupUi(){
    this->setObjectName(QStringLiteral("MainWindow"));
    this->resize(1046, 672);

    centralWidget->setObjectName(QStringLiteral("centralWidget"));

    scrollArea->setObjectName(QStringLiteral("scrollArea"));
    scrollArea->setGeometry(QRect(10, 240, 1021, 400));
    scrollArea->setWidgetResizable(true);
    scrollArea->setBackgroundRole(QPalette::Dark);  // 背景色
    scrollArea->setWidget(videoLabel);
    scrollArea->setAlignment(Qt::AlignCenter);  // 居中对齐

    widget->setObjectName(QStringLiteral("widget"));
    widget->setGeometry(QRect(10, 10, 1021, 221));
    widget->setStyleSheet(QStringLiteral(""));

    pushButton_1->setObjectName(QStringLiteral("pushButton"));
    pushButton_1->setGeometry(QRect(890, 30, 121, 31));

    pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
    pushButton_2->setGeometry(QRect(890, 80, 121, 31));
    pushButton_2->setEnabled(false);

    pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
    pushButton_3->setGeometry(QRect(890, 130, 121, 31));
    pushButton_3->setEnabled(false);

    pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
    pushButton_4->setGeometry(QRect(890, 180, 121, 31));
    pushButton_4->setEnabled(false);

    videoLabel->adjustSize();
    videoLabel->move(10,10);

    tabWidget->setObjectName(QStringLiteral("tabWidget"));
    tabWidget->setGeometry(QRect(10, 10, 871, 201));

    //菜单栏第一项： 文件
    tabWidget->addTab(menu_fi, QString());
    tabWidget->setTabText(tabWidget->indexOf(menu_fi), QObject::trUtf8("文件"));

    //菜单栏第二项： 处理
    tabWidget->addTab(menu_pr, QString());
    tabWidget->setTabText(tabWidget->indexOf(menu_pr), QObject::trUtf8("处理"));

    //菜单栏第三项： 前景
    tabWidget->addTab(menu_fo, QString());
    tabWidget->setTabText(tabWidget->indexOf(menu_fo), QObject::trUtf8("前景"));

    //菜单栏第四项： 模型
    tabWidget->addTab(menu_mo, QString());
    tabWidget->setTabText(tabWidget->indexOf(menu_mo), QObject::trUtf8("模型"));

    //菜单栏第五项： 检测
    tabWidget->addTab(menu_de, QString());
    tabWidget->setTabText(tabWidget->indexOf(menu_de), QObject::trUtf8("检测"));

    tabWidget->setCurrentIndex(0);
    this->setCentralWidget(centralWidget);
    statusBar->setObjectName(QStringLiteral("statusBar"));
    this->setStatusBar(statusBar);
    statusBar->showMessage("Everything goes well!");

    connect(pushButton_1, &QPushButton::clicked, this, &MainWindow::start);

}

void MainWindow::setUiText()
{
    this->setWindowTitle(QObject::trUtf8("行人检测"));
    pushButton_1->setText(QObject::trUtf8("开始"));
    pushButton_2->setText(QObject::trUtf8("暂停"));
    pushButton_3->setText(QObject::trUtf8("重置"));
    pushButton_4->setText(QObject::trUtf8("关闭"));
    //videoLabel->setText(QObject::trUtf8("视频播放窗口"));
}
