cmake_minimum_required(VERSION 2.8.4)
project(CodingPractice)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES google_code_jam/gcj_2013/qr_probA.cpp)
add_executable(CodingPractice ${SOURCE_FILES}  google_code_jam/gcj_2013/qr_probA.cpp)