cmake_minimum_required(VERSION 3.24)
project(uno)
set(CMAKE_CXX_STANDARD 17)

include_directories("C:/cppLibraries/asio-1.28.0/include")

link_libraries(ws2_32 wsock32)

add_subdirectory(src)