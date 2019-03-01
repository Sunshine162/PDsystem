#ifndef VIDEOPLAY_H
#define VIDEOPLAY_H

#include "../../header/core/framedifference.h"
#include "../../header/core/visualbgextractor.h"
#include "../../header/core/hogsvmdetect.h"


#include "../../header/model/md_file.h"
#include "../../header/model/md_foreground.h"

#include "../../header/view/mainwindow.h"
#include <opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <QImage>
#include <QFileDialog>
#include <QTimer>
#include <qdebug.h>

using namespace  cv;

#define PAUSE 32      //设置空格键为暂停

class VideoPlay{

public:
    VideoPlay();
    void play();
    void process();
    void initBackground();
    void getForeground();
    void detect();
    void mat2qimg();


private:
    VideoCapture capture;
    Mat frame;
    Mat proImg;
    QImage qImg;
    int rate;     //原视频帧率
    int totalFrame;     //原视频总帧数
    double costTime;    //播放视频用时
    double runSpeed;    //视频处理速度

    FdModel fdModel;
    VibeModel vbModel;
    HogWithSvm hogDetecter;
};

#endif // VIDEOPLAY_H
