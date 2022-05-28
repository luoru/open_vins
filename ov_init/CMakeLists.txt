cmake_minimum_required(VERSION 3.3)
project(ov_init)


# Include libraries (if we don't have opencv 4, then fallback to opencv 3)
# The OpenCV version needs to match the one used by cv_bridge otherwise you will get a segmentation fault!
find_package(Eigen3 REQUIRED)
find_package(OpenCV 3 QUIET)
if (NOT OpenCV_FOUND)
    find_package(OpenCV 4 REQUIRED)
endif ()
find_package(Ceres REQUIRED)
message(STATUS "OPENCV: " ${OpenCV_VERSION} " | CERES: " ${Ceres_VERSION})

# check if we have our python libs files (will search for python3 then python2 installs)
# sudo apt-get install python-matplotlib python-numpy python-dev
# https://cmake.org/cmake/help/v3.10/module/FindPythonLibs.html
find_package(PythonLibs QUIET)
option(DISABLE_MATPLOTLIB "Disable or enable matplotlib plot scripts in ov_eval" OFF)
if (PYTHONLIBS_FOUND AND NOT DISABLE_MATPLOTLIB)
    add_definitions(-DHAVE_PYTHONLIBS=1)
    message(STATUS "PYTHON VERSION: " ${PYTHONLIBS_VERSION_STRING})
    message(STATUS "PYTHON INCLUDE: " ${PYTHON_INCLUDE_DIRS})
    message(STATUS "PYTHON LIBRARIES: " ${PYTHON_LIBRARIES})
    include_directories(${PYTHON_INCLUDE_DIRS})
    list(APPEND thirdparty_libraries ${PYTHON_LIBRARIES})
endif ()

# We need c++14 for ROS2, thus just require it for everybody
# NOTE: To future self, hope this isn't an issue...
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(${OpenCV_INCLUDE_DIRS} ${EIGEN3_INCLUDE_DIRS} ${CERES_INCLUDE_DIRS})

file(GLOB INIT_SRCS src/*/*.cpp)

add_library(${PROJECT_NAME} ${INIT_SRCS})
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS} ${CERES_LIBRARIES})

