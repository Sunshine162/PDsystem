#include "../../header/model/md_file.h"

int MdFile::inputType = CAMERA;
string MdFile::filePath = "";

MdFile::MdFile(){
    inputType = CAMERA;
    filePath = "";
}

void MdFile::setInputType(int type){
    inputType = type;
}

void MdFile::setFilePath(string path){
    filePath = path;
}

int MdFile::getInputType(){
    return inputType;
}

string MdFile::getFilePath(){
    return filePath;
}
