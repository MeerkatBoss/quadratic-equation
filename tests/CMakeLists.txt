add_executable( tests main.cpp
                quadratic_tests.cpp )

target_include_directories(tests PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(tests PRIVATE
                    libquadratic
                    libtesting)