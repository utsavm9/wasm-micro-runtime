# mbed-cmake requires at least CMake 3.12
cmake_minimum_required(VERSION 3.12)

# load project upload methods (must be before mbed-cmake is loaded)
# -------------------------------------------------------------
include(../cmake/UploadMethodConfig.cmake)

# load compilers and flags
# -------------------------------------------------------------

include(../mbed-cmake/mbed-cmake.cmake NO_POLICY_SCOPE)

project(mbed-cmake-test-project LANGUAGES NONE)

# recurse to subdirectories
# -------------------------------------------------------------

add_mbed_executable(wamr_fib main.cpp)
target_compile_features(wamr_fib PRIVATE cxx_std_11)


# build report
# -------------------------------------------------------------

mbed_cmake_print_build_report()