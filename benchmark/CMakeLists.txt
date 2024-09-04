
find_package(benchmark REQUIRED)

add_executable(
    benchmark 
    benchmark.cpp
)

target_link_libraries(benchmark benchmark::benchmark MyLib)
target_include_directories(benchmark PRIVATE ${CMAKE_SOURCE_DIR}/solution)

add_custom_target(benchmark_run
    COMMAND benchmark
    DEPENDS benchmark
    COMMENT "Running benchmark"
)