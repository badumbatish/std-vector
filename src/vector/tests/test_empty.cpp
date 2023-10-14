//
// Created by Jasmine Tang on 10/13/23.
//

#include "gtest/gtest.h"
#include "vector.h"

TEST(test_empty, simple_empty) {
    auto vect = vector<int>();

    ASSERT_EQ(vect.empty(), true) << "Expected the vector to be empty";
    vect.push_back(2);
    ASSERT_EQ(vect.empty(), false) << "Expected the vector to not be empty after insertion";

}