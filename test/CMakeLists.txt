cmake_minimum_required(VERSION 3.10)

# Назва проекту
project(SimpleProject)

# Використовувати стандарт C++11
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Увімкнути Debug за замовчуванням, якщо тип збірки явно не задано
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# Вказуємо, що треба зібрати виконуваний файл з main.cpp
add_executable(SimpleProject ConsoleApplication1.cpp)
