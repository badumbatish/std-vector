//
// Created by Jasmine Tang on 10/11/23.
//

#include "gtest/gtest.h"
#include "vector.h"

TEST(test_data, simple_data) {
    auto vect = vector<int>(8);

    for (int i = 0; i < 5; i++) {
        vect.push_back(i);
    }

    auto ptr = vect.data();
    for (int i = 0; i < 5; i++) {
        ASSERT_EQ(*(ptr + i), i);
    }
}
