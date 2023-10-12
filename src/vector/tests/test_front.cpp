//
// Created by Jasmine Tang on 10/11/23.
//

#include "gtest/gtest.h"
#include "vector.h"

TEST(test_front, simple_front) {
    auto vect = vector<int>();
    vect.push_back(2);

    ASSERT_EQ(vect.front(), 2);
}