#include <cv.h>
#include <highgui.h>

int main(void)
{
	IplImage *image = 0;
	CvCapture *capture = cvCaptureFromCAM(0);

	cvNamedWindow("USB-3.0 Camera", 0 );
	cvResizeWindow("USB-3.0 Camera", 320, 240 );

	while(1)
	{
		cvGrabFrame(capture);
		image = cvRetrieveFrame(capture);

		cvShowImage("USB-3.0 Camera", image);

		if(cvWaitKey(10) >= 0)
			break;
	}

	cvReleaseCapture(&capture);
	cvDestroyWindow("USB-3.0 Camera");

	return 0;
}
