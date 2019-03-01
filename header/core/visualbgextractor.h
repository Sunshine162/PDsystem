#ifndef VISUALBGEXTRACTOR_H
#define VISUALBGEXTRACTOR_H

#include <iostream>
#include "opencv2/opencv.hpp"
using namespace cv;
using namespace std;

#define NUM_SAMPLES 20		//每个像素点的样本个数
#define MIN_MATCHES 2		//#min指数
#define RADIUS 20		 //Sqthere半径
#define SUBSAMPLE_FACTOR 16	 //子采样概率

class VibeModel
{
public:
    VibeModel(void);
    ~VibeModel(void);

    void initModel(const Mat);   //初始化
    void testAndUpdate(const Mat);  //更新模型
    Mat getMask( );     //得到处理后的前背景差分图

private:
    unsigned char ***samples;
    Mat m_mask;
};










#endif // VISUALBGEXTRACTOR_H
