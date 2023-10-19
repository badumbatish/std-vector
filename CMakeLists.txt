cmake_minimum_required(VERSION 3.24)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# https://cmake.org/cmake/help/latest/policy/CMP0135.html
# Set CMP0135 to NEW for fetchContent
cmake_policy(SET CMP0135 NEW)
SET(INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include/")

project(std::vector)









# google test

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

function(ADD_TEST_EXECUTABLE TEST_NAME SOURCE_FILE)
    add_executable(${TEST_NAME} ${CMAKE_CURRENT_LIST_DIR}/${SOURCE_FILE})

    #target_include_directories(${TEST_NAME} PRIVATE INCLUDE_DIR)
    target_link_libraries(${TEST_NAME} GTest::gtest_main vector)
    gtest_discover_tests(${TEST_NAME})
endfunction()

enable_testing() # Should only be in the root folder's CMakeLists.txt
include(GoogleTest) # Should only be in the root folder's CMakeLists.txt

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/) # For including headers-path
include(integration_tests/CMakeLists.txt)
include(src/CMakeLists.txt)

export(TARGETS vector NAMESPACE vector:: FILE vectorTargets.cmake)
set(CMAKE_EXPORT_PACKAGE_REGISTRY ON)
export(PACKAGE vector)



