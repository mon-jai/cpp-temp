cmake_minimum_required(VERSION 3.16) # needs to be >=3.14
project(OOP VERSION 0.1.0)
enable_testing()

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

#### GTest
find_package(GTest)

if(NOT GTEST_FOUND)
    # reference: https://google.github.io/googletest/quickstart-cmake.html
    include(FetchContent)
    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
    )
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)

    set(GTEST_INCLUDE_DIR ${PROJECT_BINARY_DIR}/_deps/googletest-src/googletest/include)
    set(GTEST_LIBRARIES GTest::gtest)
    set(GTEST_MAIN_LIBRARIES GTest::gtest_main)
endif()

set(SRC
    src/drink.h
    src/topping.h
)

set(UT_SRC
    test/ut_main.cpp

    test/ut_drink.h
    test/ut_topping.h
)

set(INCLUDE_DIRS
    src/
)

add_executable(ut_all
    ${UT_SRC}

    ${SRC}
)
target_link_libraries(ut_all
    ${GTEST_LIBRARIES} pthread
)
target_include_directories(ut_all PRIVATE
    ${INCLUDE_DIRS}
)
target_compile_options(ut_all PRIVATE
    -Wall -pedantic
)
include(GoogleTest)
gtest_discover_tests(ut_all)

include(CodeCoverage)
set(CODE_COVERAGE_VERBOSE ON)
set(COVERAGE_EXCLUDE
    ${PROJECT_SOURCE_DIR}/build/_deps/*
    ${PROJECT_SOURCE_DIR}/test/*
)
if(CMAKE_CXX_COMPILER_ID EQUAL "Clang")
    set(GCOVR_ADDITIONAL_ARGS
        --gcov-executable "llvm-cov gcov"
    )
endif()
append_coverage_compiler_flags()
setup_target_for_coverage_gcovr_html(
    NAME ut_all_coverage
    DEPENDENCIES ut_all
    EXCLUDE ${COVERAGE_EXCLUDE}
)