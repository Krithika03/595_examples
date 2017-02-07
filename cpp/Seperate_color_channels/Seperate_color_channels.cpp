// Loading opencv libraries
#include<opencv2/core/core.hpp>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui/highgui.hpp>

// Loading standard libraries
#include<iostream>
#include<string>

int main(int argc, char** argv){

  //Initializing variables
  std::string img1="parrot.jpg";
  cv::Mat image;

  //Reading image
  image = cv::imread(img1.c_str(), cv::IMREAD_COLOR);

  //Separating color channels
  cv::Mat dest_image[3];
  cv::split(image, dest_image);

  //checking if the image is properly read
  if(image.empty())
  {
    std::cout<<"Could not open the image"<<std::endl;
    return -1;
  }

  //Displaying the image along with extracted color channels
  cv::namedWindow ( "Displaying Window", cv::WINDOW_AUTOSIZE);
  cv::imshow ("Displaying Window",image);
  cv::namedWindow ( "Red channel Window", cv::WINDOW_AUTOSIZE);
  cv::imshow ("Red channel Window",dest_image[0]);
  cv::namedWindow ( "Green channel Window", cv::WINDOW_AUTOSIZE);
  cv::imshow ("Green channel Window",dest_image[1]);
  cv::namedWindow ( "Blue channel Window", cv::WINDOW_AUTOSIZE);
  cv::imshow ("Blue channel Window", dest_image[2]);

  //Wait for any key press from user
  cv::waitKey(0);

  // Function executed well, now exit without error.
  return 0;

}
