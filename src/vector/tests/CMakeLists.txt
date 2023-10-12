add_executable(tests "${CMAKE_CURRENT_LIST_DIR}/test_constructor.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/test_push_back.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/test_indexing.cpp")

target_include_directories(tests PRIVATE INCLUDE_DIR)

target_link_libraries(
        tests
        GTest::gtest_main
)

gtest_discover_tests(tests)