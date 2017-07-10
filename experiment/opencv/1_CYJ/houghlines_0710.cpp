#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>

using namespace cv;
using namespace std;

void help()
{
 cout << "\nThis program demonstrates line finding with the Hough transform.\n"
         "Usage:\n"
         "./houghlines <image_name>, Default is pic1.jpg\n" << endl;
}

int main()
{
  VideoCapture cap("driving4.mp4");
  Mat frame, dst, smoothed, cdst, tdst;

  if(!cap.isOpened())
  {
    cout << "Could not open the input video.." << endl ;
    return -1;
  }

  while(1)
  {
    cap.read(frame);
    if(frame.empty())
    {
	cerr << "ERROR! blank frame grabbed\n" ;
	break;
    }

// 그레이스케일로 변환
    cvtColor(frame, dst, COLOR_BGR2GRAY);

// 가우시안 블러링 적용 - 커널사이즈 5,5
    GaussianBlur(dst, smoothed, Size(5, 5), 0);

// Canny 엣지 적용
    Canny(dst, cdst, 75, 175);

// 넌제로 화소로 외곽선을 표현하므로, 흑백값을 반전한다
   threshold(cdst, tdst, 0, 125, THRESH_BINARY_INV);
//    adaptiveThreshold(cdst, tdst, 125, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 5, 0);

#if 0
  vector<Vec2f> lines;
  HoughLines(dst, lines, 1, CV_PI/180, 200, 0, 0 );

  for( size_t i = 0; i < lines.size(); i++ )
  {
     float rho = lines[i][0], theta = lines[i][1];
     Point pt1, pt2;
     double a = cos(theta), b = sin(theta);
     double x0 = a*rho, y0 = b*rho;
     pt1.x = cvRound(x0 + 1000*(-b));
     pt1.y = cvRound(y0 + 1000*(a));
     pt2.x = cvRound(x0 - 1000*(-b));
     pt2.y = cvRound(y0 - 1000*(a));
     line( cdst, pt1, pt2, Scalar(0,0,255), 3, CV_AA);
  }

#else
  vector<Vec4i> lines;
  HoughLinesP(cdst, lines, 1, CV_PI/180, 200, 70, 40 );
  for( size_t i = 0; i < lines.size(); i++ )
  {
    Vec4i l = lines[i];
    line( tdst, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0,255,0), 3, CV_AA);
  }

#endif
   imshow("source", dst);
   imshow("smoothing", smoothed);
   imshow("canny edge", cdst);
   imshow("threshold", tdst);

   if(waitKey(10)>= 0) break;
   }

   cap.release();
   destroyAllWindows();

   return 0;
}

