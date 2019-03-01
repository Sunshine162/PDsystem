#ifndef FRAMEDIFFERENCE_H
#define FRAMEDIFFERENCE_H

#include "../../header/model/md_foreground.h"

#include <stdio.h>
#include <iostream>
#include "opencv2/opencv.hpp"
#include <cv.h>
#include <cxcore.h>
#include <highgui.h>
#include <iostream>
using namespace cv;
using namespace std;


class FdModel{

public:
    FdModel();
    void doDifference(Mat& );
    void initModel(Mat& );

private:
    vector<vector<Point>> contours;  //定义了一个储存轮廓外形的容器
    vector<Vec4i> her;
    VideoCapture video;
    Mat frImg;
    Mat bkImg;
    Mat diff;
};




#endif // FRAMEDIFFERENCE_H
