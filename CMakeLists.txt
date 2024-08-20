cmake_minimum_required(VERSION 3.2)

project(myPet)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${PROJECT_SOURCE_DIR}/include)
add_executable(MyProject source/main.cpp source/snake.cpp)