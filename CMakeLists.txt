cmake_minimum_required(VERSION 3.1)

project(rtow VERSION 0.1)

set(SOURCE_DIR "./")

file (GLOB SOURCES "${SOURCE_DIR}/src/*.cc")

file (GLOB HEADERS "${SOURCE_DIR}/include/*.h")

add_executable(rtow ${SOURCES} ${HEADERS})

target_include_directories(rtow PRIVATE "${SOURCE_DIR}/include/")

target_compile_features(rtow PUBLIC cxx_std_17)


