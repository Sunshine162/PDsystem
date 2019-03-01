#include "../../header/core/framedifference.h"


FdModel::FdModel(){
//    contours = NULL;
//    her = NULL;
//    video = NULL;
//    frImg = NULL;
//    Mat = NULL;
//    Mat = NULL;
}


//用第一帧初始化背景，前景，两者之差
void FdModel::initModel(Mat& firstFrame){
    frImg.create(firstFrame.cols,firstFrame.rows,CV_32FC(1));
    bkImg.create(firstFrame.cols,firstFrame.rows,CV_32FC(1));
    diff.create(firstFrame.cols,firstFrame.rows,CV_32FC(1));
    cvtColor(firstFrame,frImg,CV_RGB2GRAY);
    cvtColor(firstFrame,bkImg,CV_RGB2GRAY);
}


void FdModel::doDifference(Mat& frame){
    cvtColor(frame,frImg,CV_RGB2GRAY);
    frImg.copyTo(diff);    //将frimg复制到frame

    absdiff(diff,bkImg,diff);  //第三个参数frame等于(frame - bkimg)的绝对值
    //threshold(diff,frImg,50,255,CV_THRESH_BINARY);  //使用Threshold二值
    threshold(diff,frImg,MdForeground::getGrayThreshold(),255,CV_THRESH_BINARY);

    //找到轮廓
    //contours参数为检测的轮廓数组，每一个轮廓用一个point类型的vector表示
    //hiararchy参数和轮廓个数相同，每个轮廓contours[ i ]对应4个hierarchy元素hierarchy[i][0]~hierarchy[i][3]，
    //分别表示后一个轮廓、前一个轮廓、父轮廓、内嵌轮 廓的索引编号，如果没有对应项，该值设置为负数。
    //CV_RETR_TREE：建立一个等级树结构的轮廓
    findContours(frImg,contours,her,CV_RETR_TREE,CV_CHAIN_APPROX_SIMPLE,Point(0,0));
    //vector<Rect> boundRect( contours.size() );     //包围点集的最小矩形vector

    double area;      //第 i 个矩形的面积
    double ratio;     //第 i 个矩形的高宽比
    for (int i=0;i<contours.size();i++)
    {
        Rect rect=boundingRect(contours[i]);
        ratio = (double)rect.height / rect.width;
        if(ratio>=MdForeground::getMinAspectRatio() && ratio<=MdForeground::getMaxAspectRatio())
        {
            area=fabs(contourArea(contours[i]));
            if (area>MdForeground::getMinArea() && area <MdForeground::getMaxArea())
                rectangle( frame, rect, CV_RGB(0,0,525), 1, 8, 0 );
        }
    }
}

