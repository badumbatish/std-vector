//
// Created by Jasmine Tang on 10/13/23.
//

#include "gtest/gtest.h"
#include "vector.h"

TEST(test_empty, simple_empty) {
    auto vect = vector<int>(8);

    ASSERT_EQ(vect.empty(), true);
    vect.push_back(2);
    ASSERT_EQ(vect.empty(), false);

}