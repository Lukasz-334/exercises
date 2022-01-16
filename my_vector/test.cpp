#include "gtest/gtest.h"
#include "vector_v2.hpp"

TEST(DefaultConstructor, constructorTest) {
    vector<int> v;

    ASSERT_EQ(v.numberOfObjects, 1);
}

TEST(Constructor, checksTheNumberOfElementsInTheConstructor) {
    vector<int> v2(5);

    ASSERT_EQ(v2.size(), 5);
}

TEST(copyConstructor, testTheCorrectnessOfTheCopiedElements) {
    vector<int> v{1, 2, 3, 4, 5};
    vector<int> v2 = v;

    ASSERT_EQ(v2[3], 4);
    ASSERT_EQ(v2[0], 1);
    ASSERT_EQ(v2[4], 5);
}

TEST(copyingAssignmentOperator, correctCopyingOfData) {
    vector<int> v1{1, 2, 3, 4, 5};
    vector<int> v2{4, 4, 4, 4, 4, 4};

    v2 = v1;

    ASSERT_EQ(v2[3], 4);
    ASSERT_EQ(v2[0], 1);
    ASSERT_EQ(v2[4], 5);
    ASSERT_EQ(v1[3], 4);
    ASSERT_EQ(v1[0], 1);
    ASSERT_EQ(v1[4], 5);
}
