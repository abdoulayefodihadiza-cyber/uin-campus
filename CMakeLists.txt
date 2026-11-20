cmake_minimum_required(VERSION 3.20)
project(uin-campus CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(uincampus_core
    src/version.cpp
    src/regles.cpp
    src/saisie.cpp
    src/calculs.cpp
)
target_include_directories(uincampus_core PUBLIC include)
target_compile_definitions(uincampus_core PRIVATE UIN_VERSION="1.0")

if(UIN_ACTIVER_SANITIZERS)
    add_compile_options(-fsanitize=address,undefined -fno-omit-frame-pointer)
    add_link_options(-fsanitize=address,undefined)
endif()

add_executable(uin-campus app/main.cpp)
target_link_libraries(uin-campus PRIVATE uincampus_core)
