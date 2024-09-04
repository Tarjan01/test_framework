cmake_minimum_required(VERSION 3.24)
# g++ *.cpp -o main -lfaiss -fopenmp -lblas

project(TestFramework)

# set(CMAKE_BUILD_TYPE Debug)

if(CMAKE_BUILD_TYPE MATCHES Debug)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0")
    add_compile_options("-fsanitize=address" "-fno-omit-frame-pointer" "-fsanitize=undefined")
    add_link_options("-fsanitize=address" "-fno-omit-frame-pointer" "-fsanitize=undefined")
endif()

add_subdirectory(data_mk)
add_subdirectory(solution)
add_subdirectory(benchmark)