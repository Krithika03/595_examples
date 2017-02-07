#include <opencv2/imgproc/imgproc.hpp>
#include<opencv2/core/core.hpp>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui/highgui.hpp>

#include<iostream>
#include<string>

int main(int argc, char** argv) {
  //Initializing variables
  std::string img1 = "parrot.jpg";
  cv::Mat image_color, image_bw;

  //Reading image
  image_color = cv::imread(img1.c_str(), cv::IMREAD_COLOR);

  //Converting to grayscale
  cv::cvtColor(image_color, image_bw, cv::COLOR_RGB2GRAY);

  //declaring vector for compression
  std::vector<int> compression_parameters1;
  compression_parameters1.push_back(cv::IMWRITE_PNG_COMPRESSION);
  compression_parameters1.push_back(9);

  //Writing image
  cv::imwrite("output1.PNG", image_bw, compression_parameters1);

  return 0;

}
