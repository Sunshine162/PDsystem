#include "../../header/model/md_foreground.h"

bool MdForeground::isGetROI = false;
string MdForeground::method = "Background Difference";
double MdForeground::minAspectRatio = 0.5;
double MdForeground::maxAspectRatio = 3.0;
int MdForeground::grayThreshold = 128;
int MdForeground::minArea = 1000;
int MdForeground::maxArea = 12000;

void MdForeground::setIsGetROI(bool _isGetROI){
    isGetROI = _isGetROI;
}

bool MdForeground::getIsGetROI(){
    return isGetROI;
}

void MdForeground::setMethod(string _method){
    method = _method;
}

string MdForeground::getMethod(){
    return  method;
}

void MdForeground::setMinAspectRatio(double _minAspectRatio){
    minAspectRatio = _minAspectRatio;
}

double MdForeground::getMinAspectRatio(){
    return minAspectRatio;
}

void MdForeground::setMaxAspectRatio(double _maxAspectRatio){
    maxAspectRatio = _maxAspectRatio;
}

double MdForeground::getMaxAspectRatio(){
    return maxAspectRatio;
}

void MdForeground::setGrayThreshold(int _grayThreshold){
    grayThreshold = _grayThreshold;
}

int MdForeground::getGrayThreshold(){
    return  grayThreshold;
}

void MdForeground::setMinArea(int _minArea){
    minArea = _minArea;
}

int MdForeground::getMinArea(){
    return minArea;
}

void MdForeground::setMaxArea(int _maxArea){
    maxArea = _maxArea;
}

int MdForeground::getMaxArea(){
    return maxArea;
}
