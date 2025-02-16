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

void test_eigen()
{
    Eigen::Matrix3d mat1, mat2;
    mat1 << 1, 2, 3, 4, 5, 6, 7, 8, 9;
    mat2 << 9, 8, 7, 6, 5, 4, 3, 2, 1;
    Eigen::Matrix3d mat = mat1 * mat2;
    std::cout << mat << std::endl;
}

Eigen::Matrix3d eigen_add(Eigen::Matrix3d a, Eigen::Matrix3d b)
{
    return a + b;
}

Eigen::Matrix3d eigen_sub(Eigen::Matrix3d a, Eigen::Matrix3d b)
{
    return a - b;
}