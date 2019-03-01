#ifndef MD_DETECT_H
#define MD_DETECT_H


#include <iostream>
#include <string.h>
using namespace std;

class MdDetect{

public:
    static void setIsDetect(bool );
    static void setClassifier(string );
    static void setModelPath(string );

    static bool getIsDetect( );
    static string getClassifier( );
    static string getModelPath( );

private:
    static bool isDetect;
    static string classifier;
    static string modelPath;

};


#endif // MD_DETECT_H
