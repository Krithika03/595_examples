/*
1. load video
2. seperate 1st frame
3. display first frame
*/

#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>

using namespace cv;
int main(int argc, char** argv)
{
    String filename = "Spiderman.mp4";
    VideoCapture capture(filename);
    Mat frame;

    if( !capture.isOpened() )
      throw "Error when reading steam_avi";

    namedWindow( "Spiderman", 1 );
    for( ; ; )
    {
      capture >> frame;
      if(frame.empty())
        break;
      imshow("Spiderman",frame);
      waitKey(0);
      //waitKey(0);
    }
    waitKey(0);
    waitKey(0);
}
