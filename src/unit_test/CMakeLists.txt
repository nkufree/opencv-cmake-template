add_executable(unit_test unit_test.cpp eigen_test.cpp opencv_test.cpp)

target_link_libraries(unit_test ${OpenCV_LIBS} example GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)
