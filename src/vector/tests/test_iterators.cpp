//
// Created by Jasmine Tang on 10/13/23.
//

#include "gtest/gtest.h"
#include "vector.h"

TEST(test_iterator_begin, simple_begin) {
    auto v = vector<int>();

    for(int i=0 ; i < 3; i++) {
        v.push_back(i);
    }

    for(int i=0 ; i < 3; i++) {
        ASSERT_EQ(*(v.begin()+i), v[i]) << "Expected equality between using iterators and operator[]";
    }

}

TEST(test_iterator, ranged_based) {
    auto v = vector<int>();

    for(int i=0 ; i < 3; i++) {
        v.push_back(i);
    }

    for (auto i : v) {
        ASSERT_EQ(i, v[i]) << "Expected equality between using range-based for-loop and operator[]";
    }
}