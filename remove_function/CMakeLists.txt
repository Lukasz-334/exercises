include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


cmake_minimum_required(VERSION 3.10)
project(remove_function)

enable_testing()

set(FLAGS
    -Wall
    -Wconversion
    -Wextra
    -Werror
)

add_executable(remove remove.cpp)
target_compile_options(remove PRIVATE ${FLAGS})
target_compile_features(remove PRIVATE cxx_std_20)


add_executable(test-gt test.cpp remove.hpp)
target_link_libraries(test-gt gtest_main)
add_test(NAME example_test COMMAND example)


