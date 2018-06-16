cmake_minimum_required(VERSION 3.10)
project(tp2_cg)

set(CMAKE_CXX_STANDARD 11)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

include_directories(includes/)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

add_executable(tp2 src/main.cpp includes/Interfaces/Window.hpp includes/Windows/MainWindow.hpp src/Windows/MainWindow.cpp includes/Utils/Commons.hpp includes/Domain/Polygon.hpp src/Domain/Polygon.cpp includes/Applications/MainApplication.hpp includes/Interfaces/Application.hpp src/Applications/MainApplication.cpp includes/Utils/Utils.hpp includes/Domain/ColorPicker.hpp includes/Domain/Color.hpp src/Domain/Color.cpp src/Domain/ColorPicker.cpp)
target_link_libraries(tp2 ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})
