cmake_minimum_required(VERSION 3.10)
project(MetricsTracker)

set(CMAKE_CXX_STANDARD 14)

# Specify the path to your Qt installation
set(CMAKE_PREFIX_PATH /usr/lib/aarch64-linux-gnu/cmake/Qt5)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

add_executable(MetricsTracker src/main.cpp src/mainwindow.cpp src/mainwindow.h)
target_link_libraries(MetricsTracker Qt5::Widgets)
