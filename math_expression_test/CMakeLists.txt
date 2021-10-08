include(FetchContent)
FetchContent_Declare(
  googletest

  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)



cmake_minimum_required(VERSION 3.10)
project(mathExpressionTest)

enable_testing()

set(FLAGS
    -Wall
    -Wconversion
    -Wextra
    -Werror
    
)

add_executable(test-gt test.cpp mathExpression.cpp)
target_link_libraries(test-gt gtest_main)
target_compile_options(test-gt PRIVATE ${FLAGS})
add_test(NAME example_test COMMAND ${PROJECT_NAME}-gt)
