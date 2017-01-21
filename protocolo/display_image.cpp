#include <opencv2/core/core.hpp>
#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main( int argc, const char** argv ){
    /*Mat frame;
    Mat src = imread("photo.png", CV_LOAD_IMAGE_UNCHANGED);

    Mat s(250,250,CV_8UC3,Scalar(00,00,00));     
    


    VideoCapture cap;
    cap.open(0);
    if( !cap.isOpened() ){
        cout << "Could not initialize capturing...\n";
    }else{  
        Mat frame(480,640,CV_8UC3,Scalar(0,0,0));
        //for(int i=0; i<1; i++)    cap >> frame;

        /*char key;
        bool t=true;
        while (t && cap.grab()) {
            cap.retrieve(frame);
            imshow("BGR image", frame);
            if (key == 115){  
                imwrite("photo.png", frame);
                t = false;
                destroyWindow("BGR image");
            }
            key = waitKey(20);
        }*/
          /*for(int i=0; i<frame.rows; i++){
            for(int j=0; j<frame.cols; j++){
                Vec3b bgrPixel = frame.at<Vec3b>(i, j);
                bgrPixel[0] = 50;
                frame.at<Vec3b>(Point(j,i)) = bgrPixel;
                cout << bgrPixel << "  ";
            }
            cout << endl;
         }

        //namedWindow( "asd", 1 );
        //imshow("asd", frame);
    }


    cout << "ola" << endl;*/

     Mat src = imread("pho.png", CV_LOAD_IMAGE_UNCHANGED);
     if (src.empty()){
          cout << "Error : Image cannot be loaded..!!" << endl;
          return 0;
     }

    //BGR 
    /*cout << src.rows<< " - " <<src.cols << endl;
    for(int i=0; i<src.rows; i++){
        for(int j=0; j<src.cols; j++){
            Vec3b bgrPixel = src.at<Vec3b>(j, i);
            bgrPixel[0] = 200;
            // b = (int)bgrPixel(0)
            //bgrPixel[0] = 0;
            src.at<Vec3b>(Point(j,i)) = bgrPixel;
            cout << bgrPixel << "  ";
        }
        cout << endl;
     }*/

     namedWindow("window", WINDOW_NORMAL); //window name 
     resizeWindow("window", 250, 250); //window name 
     imshow("window", src); //show image store in img*/
     waitKey(0);
     
     /*destroyWindow("asd");
     
     return 0;*/
}