#ifndef MYFILE_H
#define MYFILE_H

#include <iostream>
#include <string.h>
using namespace std;

//如果是笔记本，0打开的是自带的摄像头，1 打开外接的相机
#define CAMERA 0
#define LOCAL_VIDEO 2

class MdFile{
public:
    MdFile();
    static void setInputType(int type);
    static void setFilePath(string path);
    static int getInputType();
    static string getFilePath();
private:
    static int inputType;
    static string filePath;
};


#endif // MYFILE_H
