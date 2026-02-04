cmake_minimum_required(VERSION 3.8...3.31)
project(HW8)

# Використовувати стандарт C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Boost REQUIRED COMPONENTS system filesystem thread)

add_executable(tcp_server server.cpp)

target_link_libraries(tcp_server PRIVATE
	Boost::system
	Boost::filesystem
	Boost::thread )
	
add_executable(tcp_client client.cpp) 

target_link_libraries(tcp_client PRIVATE
	Boost::system )
