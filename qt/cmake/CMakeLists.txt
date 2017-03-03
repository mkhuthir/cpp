# By: Muthanna A. Attyah 2017

cmake_minimum_required(VERSION 3.5)

project(Qt)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(Qt5Widgets REQUIRED)

#Qt Examples
ADD_EXECUTABLE(win      src/win.cpp)
ADD_EXECUTABLE(button   src/button.cpp)
ADD_EXECUTABLE(button2  src/button2.cpp)
ADD_EXECUTABLE(slider   src/slider.cpp)
ADD_EXECUTABLE(qimage   src/qimage.cpp)

TARGET_LINK_LIBRARIES(win       Qt5::Widgets)
TARGET_LINK_LIBRARIES(button    Qt5::Widgets)
TARGET_LINK_LIBRARIES(button2   Qt5::Widgets)
TARGET_LINK_LIBRARIES(slider    Qt5::Widgets)
TARGET_LINK_LIBRARIES(qimage    Qt5::Widgets)





