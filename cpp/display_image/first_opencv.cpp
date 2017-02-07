#include<opencv2/core/core.hpp>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui/highgui.hpp>

#include<iostream>
#include<string>

using namespace cv;
using namespace std;
int main( int argc, char** argv ) {
  string imageName("/Users/krithika/Desktop/Portfolio/IMG_1496.JPG");
  if( argc > 1 )
  {
    imageName = argv[1];

  }

  Mat image;
  image = imread(imageName.c_str(), IMREAD_COLOR);

  if( image.empty() )
  {
    cout<< "Could not open or finf the image"<<std::endl;
    return -1;
  }

  namedWindow( "Display window", WINDOW_AUTOSIZE);
  imshow("Display window",image);

  waitKey(0);
  return 0;
}
