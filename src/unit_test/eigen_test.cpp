#pragma once
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "example/example.h"

class EigenTest : public ::testing::Test
{
protected:
    virtual void SetUp()
    {
        mat1 << 1, 2, 3, 4, 5, 6, 7, 8, 9;
        mat2 << 10, 11, 12, 13, 14, 15, 16, 17, 18;
    }

    virtual void TearDown()
    {
    }

    Eigen::Matrix3d mat1, mat2;

};

TEST_F(EigenTest, Add)
{
    Eigen::MatrixXd result = eigen_add(mat1, mat2);
    EXPECT_EQ(result.rows(), 3);
    EXPECT_EQ(result.cols(), 3);
    EXPECT_EQ(result, mat1 + mat2);
}

TEST_F(EigenTest, Sub)
{
    Eigen::MatrixXd result = eigen_sub(mat1, mat2);
    EXPECT_EQ(result.rows(), 3);
    EXPECT_EQ(result.cols(), 3);
    EXPECT_EQ(result, mat1 - mat2);
}