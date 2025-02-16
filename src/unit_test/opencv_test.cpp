#include <gtest/gtest.h>
#include <opencv2/opencv.hpp>

TEST(OpenCVTest, TestOpenCV)
{
    cv::Mat3b img(100, 100);
    img(cv::Rect(10, 10, 50, 50)) = cv::Vec3b(255, 0, 0);
    EXPECT_EQ(img(15, 15), cv::Vec3b(255, 0, 0));
}