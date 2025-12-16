cmake_minimum_required(VERSION 3.10)
project(lessons)

set(CMAKE_CXX_STANDARD 17)

# Указать путь к MinGW (если нужно)
set(CMAKE_C_COMPILER "C:/soft/mingw64/bin/gcc.exe")
set(CMAKE_CXX_COMPILER "C:/soft/mingw64/bin/g++.exe")

# Создаем исполняемый файл
add_executable(test main.cpp common_string.h common_string.cpp)

# Пути к библиотекам GTest
target_link_directories(test PRIVATE ${CMAKE_SOURCE_DIR}/googletest/build/lib)

# Пути к include-файлам GTest
target_include_directories(test PRIVATE ${CMAKE_SOURCE_DIR}/googletest/googletest/include)

# Линковка gtest и gtest_main
target_link_libraries(test PRIVATE gtest gtest_main)
