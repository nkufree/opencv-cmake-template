cmake_minimum_required (VERSION 3.8)

## 如果支持，请为 MSVC 编译器启用热重载。
if (POLICY CMP0141)
    cmake_policy(SET CMP0141 NEW)
    set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

## 定义项目名
project ("opencv_cmake_template")

## 设置输出目录
### 设置静态库的输出目录为构建目录下的 lib 文件夹
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

### 设置动态库的输出目录为构建目录下的 lib 文件夹
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

### 设置可执行文件的输出目录为构建目录下的 bin 文件夹
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

### 设置安装目录为构建目录下的 install 文件夹
SET(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/install)

## 设置C++标准为17
set(CMAKE_CXX_STANDARD 17)


## 设置MSVC编译器的警告级别为4，输出一些常见的警告信息，规范代码风格
# add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/W4>")

## 解决VS性能探查器找不到pcb文件的问题
if(MSVC)
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /Zi")
    set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} /DEBUG /OPT:REF /OPT:ICF")
    set(CMAKE_SHARED_LINKER_FLAGS_RELEASE "${CMAKE_SHARED_LINKER_FLAGS_RELEASE} /DEBUG /OPT:REF /OPT:ICF")
endif()

## 启用测试
enable_testing()

## 添加第三方依赖
### 在添加gtest之前，先解决gtest的编译问题
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
### 部分使用Cmake构建的第三方库可以放在deps文件夹下，所以在这里添加这个文件夹作为子目录
add_subdirectory(deps)

## 添加OpenCV库
### TODO: 请根据实际情况修改OpenCV的路径
SET(OpenCV_DIR "E:/software/opencv/build")
find_package(OpenCV CONFIG REQUIRED)
### 打印OpenCV的相关信息
message(STATUS "OpenCV_INCLUDE_DIRS: ${OpenCV_INCLUDE_DIRS}")
include_directories(${OpenCV_INCLUDE_DIRS})
## 下面两个库位于deps文件夹下
### eigen使用模板编写，在这里只通过头文件引入
include_directories (${CMAKE_CURRENT_SOURCE_DIR}/deps/eigen-3.4.0)
## googletest
find_package(GTest CONFIG QUIET)

## 解决中文乱码问题
### 设置MSVC编译器的源代码字符集为UTF-8
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/source-charset:utf-8>")
### 设置MSVC编译器的执行字符集为GBK
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/execution-charset:gbk>")

add_subdirectory(src)
# TODO: 如有需要，请添加测试并安装目标。

