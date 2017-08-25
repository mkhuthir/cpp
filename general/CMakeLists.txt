
# By: Muthanna A. Attyah 2017
#

cmake_minimum_required(VERSION 3.5)

project(general)

SET(CMAKE_C_COMPILER /usr/bin/gcc)
SET(CMAKE_CXX_COMPILER /usr/bin/g++)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

ADD_EXECUTABLE(fileview         src/fileview.c)
ADD_EXECUTABLE(forloop          src/forloop.c)
ADD_EXECUTABLE(hello            src/hello.c)
ADD_EXECUTABLE(getoption	src/getoption.c)
ADD_EXECUTABLE(myheader         src/myheader.c src/myheadermain.c)

#ADD_EXECUTABLE(hello2           src/hello2.cpp)
#ADD_EXECUTABLE(input            src/input.cpp)
