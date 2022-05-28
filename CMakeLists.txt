cmake_minimum_required(VERSION 3.0)
project(vio)

include_directories(ov_core/src
                    ov_init/src
                    ov_msckf/src)

add_subdirectory(ov_core)
add_subdirectory(ov_init)
add_subdirectory(ov_msckf)