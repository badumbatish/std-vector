//
// Created by Jasmine Tang on 10/13/23.
//

#include <vector>

#include "vector.h"

#include "gtest/gtest.h"

TEST(itest_push_back, size) {
    auto v1 = std::vector<int>();
    auto v2 = vector<int>();

    for (int i=0 ; i <  100; i++) {
        v1.push_back(i);
        v2.push_back(i);

        ASSERT_EQ(v1.size(), v2.size()) << "Expected size of std::vector and vector to be equal";
    }

}