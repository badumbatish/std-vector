//
// Created by Jasmine Tang on 10/11/23.
//

#include "gtest/gtest.h"
#include "vector.h"

TEST(test_push_back, push_back_within_capacity) {
// Expect two strings not to be equal.
    auto vect = vector<int>();
    vect.push_back(2);
    EXPECT_EQ(vect.size(), 1);
    EXPECT_EQ(vect[0], 2);
}

TEST(test_push_back, push_back_past_capacity) {
// Expect two strings not to be equal.
    auto vect = vector<int>();

    for(int i=0; i < 100; i++) {
        ASSERT_EQ(vect.size(), i);
        vect.push_back(2);
    }

    ASSERT_EQ(vect.size(), 100);
    ASSERT_GE(vect.capacity(), 100);
}