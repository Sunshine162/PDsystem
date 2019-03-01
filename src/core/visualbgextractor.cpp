#include "../../header/core/visualbgextractor.h"

using namespace std;
using namespace cv;

int c_xoff[9] = {-1,  0,  1, -1, 1, -1, 0, 1, 0};  //x的邻居点
int c_yoff[9] = {-1,  0,  1, -1, 1, -1, 0, 1, 0};  //y的邻居点

VibeModel::VibeModel(void)
{
    samples = NULL;
}
VibeModel::~VibeModel(void)
{
    delete samples;
}


void VibeModel::initModel(Mat firstFrame)
{
    Mat _image;
    cvtColor(firstFrame, _image, CV_RGB2GRAY);      //将单帧RGB图像转换为灰度图


    //分配空间与初始化

    //动态分配三维数组，samples[][][NUM_SAMPLES]存储前景被连续检测的次数
    samples=new unsigned char **[_image.rows];
    for (int i=0;i<_image.rows;i++)
    {
        samples[i]=new unsigned char *[1024];
        //samples[i]=new unsigned char *[_image.cols];
        for (int j=0;j<_image.cols;j++)
        {
            samples[i][j]=new unsigned char [NUM_SAMPLES+1];
            for (int k=0;k<NUM_SAMPLES+1;k++)
            {
                samples[i][j][k]=0;
            }
        }
    }
    m_mask = Mat::zeros(_image.size(),CV_8UC1);    //CV_8UC1,8代表字长8位，1代表1个通道

    /********************* 从第一针初始化模型 ************************/
    RNG rng;      //RNG为随机数产生类
    int row, col;

    for(int i = 0; i < _image.rows; i++)
    {
        for(int j = 0; j < _image.cols; j++)
        {
            for(int k = 0 ; k < NUM_SAMPLES; k++)
            {
                // Random pick up NUM_SAMPLES pixel in neighbourhood to construct the model
                int random = rng.uniform(0, 9);      //产生一个从0到9之间的随机int型数

                row = i + c_yoff[random];
                if (row < 0)
                    row = 0;
                if (row >= _image.rows)
                    row = _image.rows - 1;

                col = j + c_xoff[random];
                if (col < 0)
                    col = 0;
                if (col >= _image.cols)
                    col = _image.cols - 1;

                samples[i][j][k]=_image.at<uchar>(row, col);
            }

        }
    }


}



/********************* 更新模型 **************************/
void VibeModel::testAndUpdate(const Mat frame)
{
    Mat _image;
    cvtColor(frame, _image, CV_RGB2GRAY);

    RNG rng;

    for(int i = 0; i < _image.rows; i++)
    {
        for(int j = 0; j < _image.cols; j++)
        {
            int matches(0), count(0);      //matches为匹配数
            int dist;     //差值

            while(matches < MIN_MATCHES && count < NUM_SAMPLES)
            {
                dist = abs(samples[i][j][count] - _image.at<uchar>(i, j));
                if (dist < RADIUS)
                    matches++;
                count++;
            }

            if (matches >= MIN_MATCHES)
            {
                // It is a background pixel  它是一个背景像素点
                samples[i][j][NUM_SAMPLES]=0;

                // Set background pixel to 0  将背景像素点设置为0（黑色）；
                m_mask.at<uchar>(i, j) = 0;

                // 如果一个像素是背景点，那么它有 1 / defaultSubsamplingFactor 的概率去更新自己的模型样本值
                int random = rng.uniform(0, SUBSAMPLE_FACTOR);
                if (random == 0)
                {
                    random = rng.uniform(0, NUM_SAMPLES);
                    samples[i][j][random]=_image.at<uchar>(i, j);
                }

                // 同时也有 1 / defaultSubsamplingFactor 的概率去更新它的邻居点的模型样本值
                random = rng.uniform(0, SUBSAMPLE_FACTOR);
                if (random == 0)
                {
                    int row, col;
                    random = rng.uniform(0, 9);
                    row = i + c_yoff[random];
                    if (row < 0)
                        row = 0;
                    if (row >= _image.rows)
                        row = _image.rows - 1;

                    random = rng.uniform(0, 9);
                    col = j + c_xoff[random];
                    if (col < 0)
                        col = 0;
                    if (col >= _image.cols)
                        col = _image.cols - 1;

                    random = rng.uniform(0, NUM_SAMPLES);
                    samples[i][j][random]=_image.at<uchar>(i, j);
                }
            }
            else
            {
                // It is a foreground pixel 它是一个前景像素点
                samples[i][j][NUM_SAMPLES]++;

                // Set foreground pixel to 255   //将前景像素点设置为255（白色）
                m_mask.at<uchar>(i, j) = 255;

                //如果某个像素点连续N次被检测为前景，则认为一块静止区域被误判为运动，将其更新为背景点
                if(samples[i][j][NUM_SAMPLES]>50)
                {
                    int random = rng.uniform(0, NUM_SAMPLES);
                    if (random == 0)
                    {
                        random = rng.uniform(0, NUM_SAMPLES);
                        samples[i][j][random]=_image.at<uchar>(i, j);
                    }
                }
            }
        }
    }
}

Mat VibeModel::getMask(){
    return m_mask;
}

