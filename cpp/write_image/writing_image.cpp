#include<opencv2/core/core.hpp>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui/highgui.hpp>

#include<iostream>
#include<string>

int main(int argc, char** argv) {
  std::string img = "IMG_1496.JPG";
  cv::Mat image;
  image = cv::imread(img.c_str(), cv::IMREAD_COLOR);
  std::vector<int> compression_parameters;
  compression_parameters.push_back(cv::IMWRITE_PNG_COMPRESSION);
  compression_parameters.push_back(9);
  cv::imwrite("output.PNG", image, compression_parameters);

  //cv::waitKey(0);
  return 0;
}
