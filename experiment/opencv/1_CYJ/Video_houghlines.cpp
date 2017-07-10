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
  Mat frame, dst, cdst;

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
    Canny(frame, dst, 125, 350, 3);
    cvtColor(dst, cdst, CV_GRAY2BGR);

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
  HoughLinesP(dst, lines, 1, CV_PI/180, 150, 100, 20 );
  for( size_t i = 0; i < lines.size(); i++ )
  {
    Vec4i l = lines[i];
    line( cdst, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0,0,255), 3, CV_AA);
  }

#endif
   imshow("source", frame);
   imshow("detected lines", cdst);

   if(waitKey(10)>= 0) break;
   }

   cap.release();
   destroyAllWindows();

   return 0;
}

