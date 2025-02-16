set(SOURCES example.cpp)
add_library(example STATIC ${SOURCES})
target_link_libraries(example common ${OpenCV_LIBS})