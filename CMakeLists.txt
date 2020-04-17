cmake_minimum_required(VERSION 3.16)
project(rapidjsonexample)

set(CMAKE_CXX_STANDARD 14)
file(COPY rapidjson/ DESTINATION ./rapidjson)

include_directories(rapidjson)

set (CMAKE_CXX_STANDARD_LIBRARIES -lstdc++fs)

add_executable(rapidjsonexample main.cpp)