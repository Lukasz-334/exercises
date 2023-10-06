#include "gtest/gtest.h"
#include "parseQuantity.hpp"

TEST(parseQuantity, correctData) {
    ASSERT_EQ(parseQuantity("123"), 123);
    ASSERT_EQ(parseQuantity("12b4"), 12);
    ASSERT_EQ(parseQuantity("0941"), 941);
    ASSERT_EQ(parseQuantity("1234567-9"), 1234567);
    ASSERT_EQ(parseQuantity("2147483646xyz"), 2147483646);
}

TEST(parseQuantity, incorrectData) {
    ASSERT_EQ(parseQuantity("asd"), 0);
    ASSERT_EQ(parseQuantity(""), 0);
    ASSERT_EQ(parseQuantity("a12"), 0);
    ASSERT_EQ(parseQuantity("  1"), 0);
    ASSERT_EQ(parseQuantity("!@#1"), 0);
}

TEST(parseQuantity, valueEqualToMaxInt) {
    ASSERT_EQ(parseQuantity("2147483647xyz"), INT_MAX);
}

TEST(parseQuantity, parsingToMaxInt) {
    ASSERT_EQ(parseQuantity("2147483648xyz"), INT_MAX);
    ASSERT_EQ(parseQuantity("9197488642Adyz"), INT_MAX);
    ASSERT_EQ(parseQuantity("5643213425617631"), INT_MAX);
    ASSERT_EQ(parseQuantity("87184511779177197hyuu"), INT_MAX);
}
