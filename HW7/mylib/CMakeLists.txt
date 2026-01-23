add_library(mylib STATIC
    src/mylib.cpp
)

target_include_directories(mylib
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)