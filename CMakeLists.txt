# Set the minimum version of CMake required for this project.
cmake_minimum_required(VERSION 3.10)

# Set the name of your project. This will be the name of your executable.
project(LATC VERSION 1.0)

# Specify the C++ standard to use.
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find the GoogleTest package.
# This assumes it is installed on the system (as you did with apt-get).
# find_package(GTest REQUIRED)

# Add the directory containing your public header files.
# This makes them accessible to all targets in your project.
include_directories(source)

# The 'add_library' command is used for your header-only library.
# The INTERFACE keyword tells CMake that this is a header-only library.
add_library(LATCHeaderLibrary INTERFACE)

# The 'target_include_directories' command adds the include directory for this library.
target_include_directories(LATCHeaderLibrary INTERFACE source)

# The 'add_executable' command creates an executable for your tests.
# This finds all .cpp files in the tests directory.
add_executable(test_vector test/test_vector.cpp)

# The 'target_link_libraries' command links your executable to the necessary libraries.
# It links to Google Test's libraries and your header library.
# target_link_libraries(test_vector PRIVATE GTest::gtest_main LATCHeaderLibrary)
target_link_libraries(test_vector PRIVATE LATCHeaderLibrary)
