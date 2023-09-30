#include "gtest/gtest.h"
#include "parseQuantity.hpp"

TEST(parseQuantity, testOfLoadingNumber) {
    ASSERT_EQ(parseQuantity("123"), 123);
    ASSERT_EQ(parseQuantity("asd"), 0);
    ASSERT_EQ(parseQuantity(""), 0);
    ASSERT_EQ(parseQuantity("12b4"), 12);
    ASSERT_EQ(parseQuantity("a12"), 0);
    ASSERT_EQ(parseQuantity("  1"), 0);
    ASSERT_EQ(parseQuantity("0941"), 941);
    ASSERT_EQ(parseQuantity("1234567-9"), 1234567);
    ASSERT_EQ(parseQuantity("!@#1"), 0);
}
