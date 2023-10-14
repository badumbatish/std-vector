//
// Created by Jasmine Tang on 10/11/23.
//

#include "gtest/gtest.h"
#include "vector.h"

TEST(test_back, simple_back) {
    auto vect = vector<int>();

    vect.push_back(2);

    ASSERT_EQ(vect.back(), 2) << "The current last element should be 2";
    vect.push_back(3);
    ASSERT_EQ(vect.back(), 3) << "The current last element should be 3";

}