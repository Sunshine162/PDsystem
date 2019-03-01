#include "../../header/view/mainwindow.h"
#include <opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <qdebug.h>

#include "../../header/core/videoplay.h"
#include <iostream>

using namespace cv;
using namespace  std;


void MainWindow::start()
{

//    qDebug() << "文件输入类型 " << MdFile::getInputType() << endl;
//    cout << "文件输入类型 " << MdFile::getFilePath() << endl;
//    qDebug() << "是否前景提取 " << MdForeground::getIsGetROI() << endl;
//    qDebug() << "是否行人检测 " << MdDetect::getIsDetect() << endl;

    VideoPlay vp;
    vp.play();
}

void MainWindow::close()
{

}

void MainWindow::pause()
{

}

void MainWindow::reset()
{

}
