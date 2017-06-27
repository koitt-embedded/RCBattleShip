#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <stdio.h>

using namespace std;
using namespace cv;

/*
void onmouse(int event, int x, int y, int flags, void* param);
void changeQuantisationGrey(Mat &image, int num_bits);

void onmouse(int event, int x, int y, int flags, void* param)
{
//좌클릭할때 그위치에서 픽셀값과 위치를 출력
        if(event == CV_EVENT_LBUTTONDOWN)
        {
                Mat *img = (Mat*)(param);
                cout <<"Mouse clicked" << (int)(*img).at<uchar>(y,x) << endl;
                cout <<"Mouse clicked" << x << "," << y << endl;
        }
}
//256단계의 gray 이미지를 2^num_bits 단계로 바꾸는 함수
void changeQuantisationGrey(Mat &image, int num_bits)
{
        CV_Assert((image.type() == CV_8UC1) && (num_bits >= 1) && (num_bits <= 8));

        uchar mask = 0xFF << (8 - num_bits);

        for (int row = 0; row < image.rows; row++)
        {
                for(int col = 0; col < image.cols; col++)
                {
                        image.at<uchar>(row, col) = image.at<uchar>(row,col) & mask;
                }
        }
}
*/

int main(void)
{
	int CAM_ID = 0;
	Mat frame;
	Mat gray_image; //그레이체널 Mat 생성
	VideoCapture cap(CAM_ID); //카메라 생성
	if(!cap.isOpened()){ //카메라 열렸는지 확인
		printf("Can't open the CAM(%d)\n",CAM_ID);
		return -1;
	}
	//이미지 해상도 얻기
	double width = cap.get(CV_CAP_PROP_FRAME_WIDTH);
	double height = cap.get(CV_CAP_PROP_FRAME_HEIGHT);
	printf("size = [%f, %f]\n", width, height);


	//윈도우 생성 및 사이즈 변경
	namedWindow("CAM_Window", 0);
	resizeWindow("CAM_Window", 1080, 720);

//	setMouseCallback("CAM_Window",onmouse, &gray_image);


	while(1){

	cap >> frame; //카메라에서 이미지 얻어오기

	
	cvtColor(frame, gray_image, CV_BGR2GRAY);  //컬러화면을 흑백으로 바꿔줌
//	changeQuantisationGrey(gray_image, 3);
        imshow("CAM_Window", gray_image); //얻어온 이미지를 윈도우에 표시

        char ch = waitKey(1);
		if(ch == 27)
		{
			cap.release();   //OpenCV는 종료를 release로 하더이다.
			break;
		}
	//destroyWindow("CAM_Window");
	}
	return 0;

	
}




