cmake_minimum_required(VERSION 3.29)
project(carRentalCommandLine)

# Bruk C++20
set(CMAKE_CXX_STANDARD 20)

# Inkluder- og kildefiler
# Dette gjør at dere ikke trenger å legge inn executables selv så lenge de ligger i mappene
include_directories(include)
file(GLOB_RECURSE SOURCES "src/*.cpp" "main.cpp")


include_directories(${CMAKE_SOURCE_DIR}/sqlite3)
set(SQLITE_SRC ${CMAKE_SOURCE_DIR}/sqlite3/sqlite3.c
        include/CarController.h
        include/CustomerController.h)
# Lag kjørbar fil
add_executable(${PROJECT_NAME} ${SOURCES} ${SQLITE_SRC}
        include/storage.h)