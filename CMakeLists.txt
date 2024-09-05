cmake_minimum_required(VERSION 3.13)
project(main)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
        CACHE STRING "Vcpkg toolchain file")
set(VCPKG_TARGET_TRIPLET "x64-windows" CACHE STRING "Vcpkg target triplet")
message("CMAKE_TOOLCHAIN_FILE: ${CMAKE_TOOLCHAIN_FILE}")

find_package(GTest CONFIG REQUIRED)

include_directories(include/)

add_executable(main
        src/main.cpp
        src/unit_test.cpp
        include/shared_ptr.h
        include/shared_ptr.hpp
        include/unique_ptr.h
        include/unique_ptr.hpp
)
target_link_libraries(main
        GTest::gtest GTest::gtest_main
)