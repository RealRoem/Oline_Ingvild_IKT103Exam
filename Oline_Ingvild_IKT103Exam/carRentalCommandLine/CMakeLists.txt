cmake_minimum_required(VERSION 3.29)
project(carRentalCommandLine)

# Use C++20
set(CMAKE_CXX_STANDARD 20)

# Include directories
include_directories(include)
include_directories(${CMAKE_SOURCE_DIR}/sqlite3)

# Source files
file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "include/*.h")

# SQLite source
set(SQLITE_SRC ${CMAKE_SOURCE_DIR}/sqlite3/sqlite3.c)

# Create executable
add_executable(${PROJECT_NAME}
        main.cpp
        ${SOURCES}
        ${HEADERS}
        ${SQLITE_SRC}
)

# Link libraries if needed (for SQLite on some systems)
if(UNIX AND NOT APPLE)
    target_link_libraries(${PROJECT_NAME} pthread dl)
elseif(APPLE)
    target_link_libraries(${PROJECT_NAME} pthread)
endif()