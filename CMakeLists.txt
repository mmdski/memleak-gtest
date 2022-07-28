cmake_minimum_required(VERSION 3.14.0)
project(memleak-gtest VERSION 0.1.0)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 14)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g3 -Wall -Wextra -pedantic -Werror -fno-omit-frame-pointer -fsanitize=address")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g3 -Wall -Wextra -pedantic -Werror -fno-omit-frame-pointer -fsanitize=address")

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.12.1
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
include(CTest)
include(GoogleTest)

set(ASAN_ENV "ASAN_OPTIONS=abort_on_error=0")

string(CONCAT ASAN_ENV ${ASAN_ENV}
    ":detect_leaks=1\;"
    "LSAN_OPTIONS=suppressions=${CMAKE_CURRENT_SOURCE_DIR}/lsan.supp")

macro(add_mem_test basename fail)
    add_library(${basename} ${basename}.c)
    add_executable(${basename}-test ${basename}.cpp)
    target_link_libraries(${basename}-test ${basename} GTest::gtest GTest::gtest_main)
    gtest_add_tests(TARGET ${basename}-test
        TEST_LIST ${basename}Tests)
    set_tests_properties(${${basename}Tests}
        PROPERTIES
        ENVIRONMENT ${ASAN_ENV}
        WILL_FAIL ${fail})
endmacro()

add_mem_test(memory-leak TRUE)
add_mem_test(memory-no-leak FALSE)
add_mem_test(memory-access-after-free TRUE)
add_mem_test(memory-double-free TRUE)
