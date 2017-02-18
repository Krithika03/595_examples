//Loading opencv libraries
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/core/core.hpp>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui/highgui.hpp>

#include<iostream>
#include<string>

int main(int argc, char** argv){

  std::string img1= "Bright_on_dark.png";
  cv::Mat image,gray_image;

  image = cv::imread(img1.c_str(),cv::IMREAD_COLOR);

  cv::cvtColor(image,gray_image,cv::COLOR_RGB2GRAY);

  std::vector<int> compression_parameters1;
  compression_parameters1.push_back(cv::IMWRITE_PNG_COMPRESSION);
  compression_parameters1.push_back(9);

  cv::namedWindow("Gray image window", cv::WINDOW_AUTOSIZE);
  cv::imshow("Gray image window",gray_image);
  //cv::imwrite("Output1.PNG",gray_image,compression_parameters1);

  cv::waitKey(0);
  cv::Mat a;

  return 0;

}
