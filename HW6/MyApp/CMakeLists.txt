cmake_minimum_required(VERSION 3.8...3.31)
project(MyApp)

find_package(Boost REQUIRED)
add_executable(MyApp example.cpp)
target_link_libraries(MyApp Boost::headers)
