file(GLOB SOURCES "*.cpp")

add_library(MyLib STATIC ${SOURCES})

find_package(OpenMP REQUIRED)
if(OpenMP_CXX_FOUND)
    target_link_libraries(MyLib PRIVATE OpenMP::OpenMP_CXX)
endif()

find_library(FAISS_LIB faiss REQUIRED)
if(FAISS_LIB)
    target_link_libraries(MyLib PRIVATE ${FAISS_LIB})
endif()

find_package(BLAS REQUIRED)
if(BLAS_FOUND)
    target_link_libraries(MyLib PRIVATE ${BLAS_LIBRARIES})
endif()

target_include_directories(MyLib PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
