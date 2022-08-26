add_library(libtesting testing.cpp)

target_include_directories(libtesting PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(libtesting PUBLIC
                    libutils)