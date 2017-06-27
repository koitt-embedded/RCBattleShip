#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>

using namespace cv;
using namespace std;

int main()
{
  VideoCapture cap(0);
  Mat frame, gray;

  if(!cap.isOpened() )
  {
    cout << "Could not open the input video.." << endl ;
    return -1;
  }

  while(1)
  {
  cap.read(frame);

  if(frame.empty()) break;

  cvtColor(frame, gray, CV_BGR2GRAY);

  imshow("frame", frame);
  imshow("gray", gray);

  if(waitKey(10) >= 0) break;
  }

  cap.release();
  destroyAllWindows(); // It's not necessary !

  return 0;
}
