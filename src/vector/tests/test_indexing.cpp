//
// Created by Jasmine Tang on 10/11/23.
//

#include "gtest/gtest.h"
#include "vector.h"

TEST(test_indexing, test_square_bracket) {
    // Expect two strings not to be equal.
    auto vect = vector<int>();
    vect.push_back(2);
    EXPECT_EQ(vect[0], 2);

    vect.push_back(3);
    EXPECT_EQ(vect[0], 2);
    EXPECT_EQ(vect[1], 3);

    vect[0] = 1;
    EXPECT_EQ(vect[0], 1);


}

TEST(test_indexing, test_at) {
    // Expect two strings not to be equal.
    auto vect = vector<int>();
    vect.push_back(2);
    EXPECT_EQ(vect.at(0), 2);

    vect.push_back(3);
    EXPECT_EQ(vect.at(0), 2);
    EXPECT_EQ(vect.at(1), 3);

    vect.at(0) = 1;
    EXPECT_EQ(vect.at(0), 1);

    ASSERT_NO_THROW(vect.at(0)) << "Expected no throw when using at(0), this is safe.";
    ASSERT_ANY_THROW(vect.at(3)) << "Expected a throw when using at(3), this is not safe";
}