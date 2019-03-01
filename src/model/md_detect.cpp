#include "../../header/model/md_detect.h"


bool MdDetect::isDetect = false;
string MdDetect::classifier = "SVM";
string MdDetect::modelPath = "";


void MdDetect::setIsDetect(bool _isDetect){
    isDetect = _isDetect;
}

void MdDetect::setClassifier(string _classifier){
    classifier = _classifier;
}

void MdDetect::setModelPath(string _modelPath){
    modelPath = _modelPath;
}

bool MdDetect::getIsDetect( ){
    return isDetect;
}

string MdDetect::getClassifier( ){
    return classifier;
}

string MdDetect::getModelPath( ){
    return modelPath;
}

