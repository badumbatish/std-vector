add_executable(test_constructor "${CMAKE_CURRENT_LIST_DIR}/test_constructor.cpp")
add_executable(test_push_back "${CMAKE_CURRENT_LIST_DIR}/test_push_back.cpp")
add_executable(test_indexing "${CMAKE_CURRENT_LIST_DIR}/test_indexing.cpp")
add_executable(test_front "${CMAKE_CURRENT_LIST_DIR}/test_front.cpp")
add_executable(test_back "${CMAKE_CURRENT_LIST_DIR}/test_back.cpp")


target_include_directories(test_constructor PRIVATE INCLUDE_DIR)
target_include_directories(test_push_back PRIVATE INCLUDE_DIR)
target_include_directories(test_indexing PRIVATE INCLUDE_DIR)
target_include_directories(test_front PRIVATE INCLUDE_DIR)
target_include_directories(test_back PRIVATE INCLUDE_DIR)


target_link_libraries(test_constructor GTest::gtest_main)
target_link_libraries(test_push_back GTest::gtest_main)
target_link_libraries(test_indexing GTest::gtest_main)
target_link_libraries(test_front GTest::gtest_main)
target_link_libraries(test_back GTest::gtest_main)


gtest_discover_tests(test_constructor)
gtest_discover_tests(test_push_back)
gtest_discover_tests(test_indexing)
gtest_discover_tests(test_front)
gtest_discover_tests(test_back)