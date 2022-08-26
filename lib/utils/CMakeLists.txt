add_library(libutils double_utils.cpp
            io_utils.cpp)

target_include_directories(libutils PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR})