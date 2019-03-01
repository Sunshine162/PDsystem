#include "../../header/core/videoplay.h"

#include <time.h>
#include <qdebug.h>
#include <QTime>

#include <iostream>
using namespace  std;


VideoPlay::VideoPlay(){

    qDebug() << "初始化开始！" << endl;

    //判断输入源
    if(MdFile::getInputType() == 0){
        capture.open(0);
        rate = 30;
        qDebug() << "加载摄像头数据！" << endl;
    }else{
        qDebug() << "加载本地文件！" << endl;
        if(MdFile::getFilePath()==""){
            qDebug() << "源文件名字出错！" << endl;
        }else{
            cout << MdFile::getFilePath() << endl;
            capture.open(MdFile::getFilePath());
            qDebug() << "成功打开本地文件！" << endl;
            rate = capture.get(CV_CAP_PROP_FPS);
            totalFrame = capture.get(CV_CAP_PROP_FRAME_COUNT);
        }
    }

    if(!capture.isOpened()){
        qDebug() << "文件打开失败！" << endl;
    }

    qDebug() << "初始化成功！" << endl;
}

void VideoPlay::play(){
    clock_t start = clock();
    int frameIndex = 0;

    //判断是否需要行人检测，如果需要的话提前初始化并设置好SVM分类器
    if(MdDetect::getIsDetect()){
        qDebug() << "初始化并设置分类器" << endl;
        hogDetecter.doInit();
        hogDetecter.setSvm();
    }

    //判断是否处理视频

    capture >> frame;
    while (true)
    {
        capture >> frame;
        if (!frame.empty())
        {
              frameIndex++;     //记录当前是第几帧

            //前景提取,获取感兴趣区域
            if(MdForeground::getIsGetROI()){
                if(frameIndex == 1){
                    initBackground();
                } else{
                    getForeground();
                }
            }


            //判断是否行人检测
            if(MdDetect::getIsDetect()){
                qDebug() << "对第"<<frameIndex<<"帧进行行人检测" << endl;
                if(MdDetect::getClassifier() == "SVM"){
                    hogDetecter.doDetect(frame);
                }else{

                }
            }


            //将检测后的图像设置到Qlabel里
            mat2qimg();
            MainWindow::videoLabel->setPixmap(QPixmap::fromImage(qImg));
            MainWindow::videoLabel->update();
            QTime dieTime = QTime::currentTime().addMSecs(200); //addMsecs()里面的参数是里延迟的时间间隔
            while( QTime::currentTime() < dieTime )
                QCoreApplication::processEvents(QEventLoop::AllEvents, 100);


            //imshow("test",frame);
            //if(waitKey(10)==27)
            //        break;
        }else{
            break;
        }
    }

    clock_t end = clock();
    costTime = (double)(end - start)/CLOCKS_PER_SEC;  //将时间差值模1000，单位由毫秒转换成秒
    runSpeed = totalFrame/costTime;
    qDebug() << "处理时间： " << costTime << endl;
    if(MdFile::getInputType()==LOCAL_VIDEO){
        qDebug() << "总帧数： " << totalFrame << endl;
        qDebug() << "处理速度： " << runSpeed << endl;
    }
    qDebug() << "原帧率： " << rate << endl;
}



void VideoPlay::process(){

}

void VideoPlay::initBackground(){
    if(MdForeground::getMethod() == "Background Difference"){
        fdModel.initModel(frame);
    } else if(MdForeground::getMethod() == "Visual Background Extractor"){
        vbModel.initModel(frame);
    } else if(MdForeground::getMethod() == "Gauss Background Model"){

    } else{

    }
}

void VideoPlay::getForeground(){
    if(MdForeground::getMethod() == "Background Difference"){
        fdModel.doDifference(frame);
    } else if(MdForeground::getMethod() == "Visual Background Extractor"){
        vbModel.testAndUpdate(frame);
        frame= vbModel.getMask();
    } else if(MdForeground::getMethod() == "Gauss Background Model"){

    } else{

    }
}



void VideoPlay::detect(){

}


void VideoPlay::mat2qimg(){
    if(frame.channels()==3)           //3通道图像
    {

        cv::cvtColor(frame,frame,CV_BGR2RGB);
        qImg =QImage((const unsigned char*)(frame.data),
                     frame.cols, frame.rows,
                     frame.cols*frame.channels(),
                     QImage::Format_RGB888);
    }
    else if(frame.channels()==1)          //灰度图
    {
        qImg =QImage((const unsigned char*)(frame.data),
                     frame.cols,frame.rows,
                     frame.cols*frame.channels(),
                     QImage::Format_Indexed8);
    }
    else
    {
        qImg =QImage((const unsigned char*)(frame.data),
                     frame.cols,frame.rows,
                     frame.cols*frame.channels(),
                     QImage::Format_RGB888);
    }

}







