cmake_minimum_required(VERSION 3.1)

project(rtow VERSION 0.1)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

set(SOURCE_DIR "./")

file (GLOB SOURCES "${SOURCE_DIR}/src/*.cc")

file (GLOB HEADERS "${SOURCE_DIR}/include/*.h")

add_executable(rtow ${SOURCES} ${HEADERS})

target_include_directories(rtow PRIVATE "${SOURCE_DIR}/include/")

target_compile_features(rtow PUBLIC cxx_std_17)


