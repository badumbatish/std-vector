//
// Created by Jasmine Tang on 10/11/23.
//

#include "gtest/gtest.h"

TEST(HelloTest, BasicAssertions) {
    // Expect two strings not to be equal.
    EXPECT_STRNE("hello", "world");
    // Expect equality.
    EXPECT_EQ(7 * 6, 42);
}