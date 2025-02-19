#include "example/example.h"
#include "common/common.h"
#include <iostream>
#include <opencv2/opencv.hpp>

void example()
{
    hello();
    std::cout << "你好，世界！" << std::endl;
}

void test_img()
{
    cv::Mat3b img(100, 200);
    img(cv::Rect(10, 10, 50, 50)) = cv::Vec3b(255, 0, 0);
    cv::namedWindow("test", cv::WINDOW_AUTOSIZE | cv::WINDOW_FREERATIO);
    cv::imshow("test", img);
    cv::waitKey(0);
    cv::destroyAllWindows();
    cv::imwrite("test.png", img);
}
