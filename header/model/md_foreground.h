#ifndef MODEL_FOREGROUND_H
#define MODEL_FOREGROUND_H

#include <iostream>
#include <string.h>
using namespace std;

class MdForeground{

public:
    static void setIsGetROI(bool );
    static bool getIsGetROI();
    static void setMethod(string );
    static string getMethod();
    static void setMinAspectRatio(double);
    static double getMinAspectRatio();
    static void setMaxAspectRatio(double);
    static double getMaxAspectRatio();
    static void setGrayThreshold(int );
    static int getGrayThreshold();
    static void setMinArea(int);
    static int getMinArea();
    static void setMaxArea(int);
    static int getMaxArea();

private:
    static bool isGetROI;
    static string method;
    static double minAspectRatio;
    static double maxAspectRatio;
    static int grayThreshold;
    static int minArea;
    static int maxArea;

};

#endif // MODEL_FOREGROUND_H
