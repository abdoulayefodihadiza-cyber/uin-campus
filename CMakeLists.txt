cmake_minimum_required(VERSION 3.20)
project(uin-campus CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_library(uincampus_core)
    src/version.cpp
    src/regles.cpp
    src/saisie.cpp
    


add_executable(uin-campus main.cpp)

