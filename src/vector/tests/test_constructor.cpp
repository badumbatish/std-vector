//
// Created by Jasmine Tang on 10/11/23.
//

#include "gtest/gtest.h"
#include "vector.h"
TEST(test_constructor, basic_constructor) {
    // Expect two strings not to be equal.
    auto vect = vector<int>();
    EXPECT_EQ(vect.size(), 0) << "With the default constructor, size should be 0";

    vect = vector<int>(8);
    EXPECT_EQ(vect.size(), 8) << "With this constructor, size should be 8";

}