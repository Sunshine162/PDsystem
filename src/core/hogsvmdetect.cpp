#include "../../header/core/hogsvmdetect.h"


HogWithSvm::HogWithSvm(){
}

void HogWithSvm::doInit(){
    svm = SVM::create();
    svm = SVM::load<SVM>(MdDetect::getModelPath());
    //或者svm = Statmodel::load<SVM>("SVM_HOG.xml");
}
void HogWithSvm::setSvm(){
    Mat svecsmat = svm ->getSupportVectors();//svecsmat元素的数据类型为float
    int svdim = svm ->getVarCount();//特征向量位数
    int numofsv = svecsmat.rows;

    Mat alphamat = Mat::zeros(numofsv, svdim, CV_32F);//alphamat和svindex必须初始化，否则getDecisionFunction()函数会报错
    Mat svindex = Mat::zeros(1, numofsv,CV_64F);

    Mat Result;
    double rho = svm ->getDecisionFunction(0, alphamat, svindex);
    alphamat.convertTo(alphamat, CV_32F);//将alphamat元素的数据类型重新转成CV_32F
    Result = -1 * alphamat * svecsmat;//float


    for (int i = 0; i < svdim; ++i)
    {
        vec.push_back(Result.at<float>(0, i));
    }
    vec.push_back(rho);

    //saving HOGDetectorForOpenCV.txt
    ofstream fout("HOGDetectorForOpenCV.txt");
    for (int i = 0; i < vec.size(); ++i)
    {
        fout << vec[i] << endl;
    }

    hog_test.setSVMDetector(vec);
}

void HogWithSvm::doDetect(Mat& src){

    vector<Rect> found, found_filtered;
    hog_test.detectMultiScale(src, found, 0, Size(8,8), Size(32,32), 1.05, 2);

    //找出所有没有嵌套的矩形框r,并放入found_filtered中,如果有嵌套的话,则取外面最大的那个矩形框放入found_filtered中
    for(int i=0; i < found.size(); i++)
    {
        Rect r = found[i];
        int j=0;
        for(; j < found.size(); j++)
            if(j != i && (r & found[j]) == r)
                break;
        if( j == found.size())
            found_filtered.push_back(r);
    }

    //画矩形框，因为hog检测出的矩形框比实际人体框要稍微大些,所以这里需要做一些调整
    for(int i=0; i<found_filtered.size(); i++)
    {
        Rect r = found_filtered[i];
        r.x += cvRound(r.width*0.1);
        r.width = cvRound(r.width*0.8);
        r.y += cvRound(r.height*0.07);
        r.height = cvRound(r.height*0.8);
        rectangle(src, r.tl(), r.br(), Scalar(0,255,0), 3);
    }
}
