cmake_minimum_required(VERSION 3.21)
project(s21_SmartCalc_v2_0)

set(CMAKE_CXX_STANDARD 14)

include_directories(src/model)

add_executable(s21_SmartCalc_v2_0
        src/model/model.cc
        src/model/model.h)
