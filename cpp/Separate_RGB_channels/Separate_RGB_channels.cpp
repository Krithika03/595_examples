//Loading opencv libraries
#include<opencv2/core/core.hpp>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui/highgui.hpp>

//Loading standard libraries
#include<iostream>
#include<string>

int main(int argc, char** argv){

  //Initializing variables
  std::string img1 = "parrot.jpg";
  cv::Mat image;

  //Reading image
  image = cv::imread(img1.c_str(), cv::IMREAD_COLOR);

  //Seperating color channels
  cv::Mat dest_image[3];
  cv::split(image, dest_image);

  //checking if the image is properly read
  if(image.empty())
  {
    std::cout<<"Could not open the image"<<std::endl;
    return -1;
  }
  //Creating a blank image
  cv::Mat zero_image= cv::Mat::zeros(image.rows,image.cols,CV_8UC1);

  //Seperating blue color from the image
  cv::Mat result_blue(image.rows,image.cols,CV_8UC3);

  cv::Mat in1[] = { dest_image[0],zero_image,zero_image };
  int from_to1[] = { 0,0, 1,1, 2,2 };
  cv::mixChannels( in1, 3, &result_blue,1,from_to1, 3);

  //Seperating green color from the image
  cv::Mat result_green(image.rows,image.cols,CV_8UC3);

  cv::Mat in2[] = {zero_image,dest_image[1],zero_image};
  //int from_to2[] = {0,0 ,1,1, 2,2};
  cv::mixChannels( in2, 3, &result_green, 1, from_to1, 3);

  //Seperating Red color from the image
  cv::Mat result_red(image.rows,image.cols,CV_8UC3);

  cv::Mat in3[]= {zero_image,zero_image,dest_image[2]};
  cv::mixChannels( in3, 3, &result_red, 1, from_to1, 3);


  //Displaying the image along with extracted color channels
  cv::namedWindow ("Displaying Window", cv::WINDOW_AUTOSIZE);
  cv::imshow ("Displaying Window", image);
  cv::namedWindow("Blue Image",cv::WINDOW_AUTOSIZE);
  cv::imshow("Blue Image",result_blue);
  cv::namedWindow("Green Image",cv::WINDOW_AUTOSIZE);
  cv::imshow("Green Image",result_green);
  cv::namedWindow("Red Image",cv::WINDOW_AUTOSIZE);
  cv::imshow("Red Image",result_red);


  //Press any key to quit
  cv::waitKey(0);

  return 0;
}
