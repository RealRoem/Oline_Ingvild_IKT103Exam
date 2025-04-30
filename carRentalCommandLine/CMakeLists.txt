cmake_minimum_required(VERSION 3.30)
project(carRentalCommandLine)

# Bruk C++20
set(CMAKE_CXX_STANDARD 20)

# Inkluder- og kildefiler
# Dette gjør at dere ikke trenger å legge inn executables selv så lenge de ligger i mappene
include_directories(include)
file(GLOB_RECURSE HEADERS "include/*.h")
file(GLOB_RECURSE SOURCES "src/*.cpp" "main.cpp")

# Lag kjørbar fil
add_executable(${PROJECT_NAME} ${SOURCES})