add_executable(tests "${CMAKE_CURRENT_LIST_DIR}/test_constructor.cpp")
target_include_directories(tests PRIVATE INCLUDE_DIR)

target_link_libraries(
        tests
        GTest::gtest_main
)

gtest_discover_tests(tests)