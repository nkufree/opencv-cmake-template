## 添加所有需要编译的文件目录
### TODO: 将所有的文件夹添加在下一行括号内即可，用空格分隔
set(SUB_DIRS common unit_test example)
foreach(dir ${SUB_DIRS})
    include_directories(${dir}/include)
endforeach()

foreach(dir ${SUB_DIRS})
    add_subdirectory(${dir})
endforeach()

## 将源代码添加到此项目的可执行文件。
add_executable(main main.cpp)
target_link_libraries(main example ${OpenCV_LIBS})

add_executable(main_hello main_hello.cpp)
target_link_libraries(main_hello example ${OpenCV_LIBS})