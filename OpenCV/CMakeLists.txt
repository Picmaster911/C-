cmake_minimum_required(VERSION 3.20)
project(Project)

set(OpenCV_DIR "C:/OpenCV/install/x64/vc17/lib")
find_package(OpenCV REQUIRED)

message(STATUS "OpenCV version: ${OpenCV_VERSION}")
message(STATUS "OpenCV libs: ${OpenCV_LIBS}")
message(STATUS "OpenCV include: ${OpenCV_INCLUDE_DIRS}")

add_executable(Project main.cpp)
target_link_libraries(Project PRIVATE ${OpenCV_LIBS})
target_include_directories(Project PRIVATE ${OpenCV_INCLUDE_DIRS})

