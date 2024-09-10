CMAKE_MINIMUM_REQUIRED(VERSION 3.13.1)

project(study_boost_spirit)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(${VENDOR_LINUX_HOME}/vendor_linux.cmake)

add_subdirectory(demo01)
add_subdirectory(demo02)
add_subdirectory(demo03_complex_number)
add_subdirectory(demo04_sum)
