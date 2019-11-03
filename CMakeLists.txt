cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
project (find)


add_executable(hw helloworld.c)
add_executable(findsql findsql.cpp)
add_executable(sqlio sqlio.cpp)
#add_executable(rw rw.cpp)
add_executable(file file.cpp)
