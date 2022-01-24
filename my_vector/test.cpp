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

TEST(overloadedAccessAndAssignmentOperator, correctAccessAndAssignment) {
    vector<int> v(5);
    v[0] = 2;
    v[1] = 6;
    v[4] = 457;

    ASSERT_EQ(v[0], 2);
    ASSERT_EQ(v[1], 6);
    ASSERT_EQ(v[4], 457);
}

TEST(moveConstructor, testTheCorrectnessOfTheMoveElements) {
    vector<int> v1{3, 5, 6, 1, 6};
    vector<int> v2 = std::move(v1);

    ASSERT_EQ(v2[0], 3);
    ASSERT_EQ(v2[4], 6);
    ASSERT_EQ(v2[1], 5);
    ASSERT_EQ(v1.wsk, nullptr);
    ASSERT_EQ(v1.size(), 0);
}

TEST(moveAssignmentOperator, testOfCorrectnessOfMovingElements) {
    vector<int> v1{3, 5, 6, 1, 6};
    vector<int> v2{4, 6, 1, 3};
    v2 = std::move(v1);

    ASSERT_EQ(v2[0], 3);
    ASSERT_EQ(v2[4], 6);
    ASSERT_EQ(v2[1], 5);
    ASSERT_EQ(v1.wsk, nullptr);
    ASSERT_EQ(v1.size(), 0);
}

TEST(atFunction, displayingAndWritingDataToVector) {
    vector<int> v{4, 5, 3, 1, 9};
    v.at(1) = 45;
    v.at(2) = 78;
    bool exc = false;
    int value = v.at(3);

    ASSERT_EQ(v[1], 45);
    ASSERT_EQ(v[2], 78);
    ASSERT_EQ(value, 1);

    try {
        v.at(15);

    } catch (std::out_of_range const& re) {
        exc = true;
    }
    ASSERT_EQ(exc, true);
}

TEST(frontFunction, testOfCorrectAccessToTheFirstElement) {
    vector<int> v{4, 5, 3, 1, 9};
    int value = v.front();

    ASSERT_EQ(value, 4);
}

TEST(backFunction, testOfCorrectAccessToTheLastElement) {
    vector<int> v{4, 5, 3, 1, 9};
    int value = v.back();

    ASSERT_EQ(value, 9);
}