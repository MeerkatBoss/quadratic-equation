add_library(libquadratic quadratic.cpp)

target_include_directories(libquadratic PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(libquadratic  PRIVATE 
                    libutils)