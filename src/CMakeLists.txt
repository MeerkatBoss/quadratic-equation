add_executable(quad main.cpp quadio.cpp)

target_include_directories(quad PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(quad PRIVATE 
                    libquadratic
                    libutils)