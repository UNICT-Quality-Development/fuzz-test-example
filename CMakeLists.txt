cmake_minimum_required(VERSION 3.12)
project(cpp_fuzz_legacy LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googletest)

add_library(math_utils src/math_utils.cpp)
target_include_directories(math_utils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(math_utils_test test/math_utils_test.cpp)
target_link_libraries(math_utils_test gtest_main math_utils)
add_test(NAME math_utils_test COMMAND math_utils_test)

add_executable(fuzz_math_utils fuzz/fuzz_math_utils.cpp)
target_compile_options(fuzz_math_utils PRIVATE -fsanitize=fuzzer,address)
target_link_options(fuzz_math_utils PRIVATE -fsanitize=fuzzer,address)
target_link_libraries(fuzz_math_utils PRIVATE math_utils)
