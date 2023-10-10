#include "gtest/gtest.h"
#include "parseQuantity.hpp"

TEST(parseQuantity, parsingNumberToWrongCharacter) {
    ASSERT_EQ(parseQuantity("123!!"), 123);
    ASSERT_EQ(parseQuantity("12b4"), 12);
    ASSERT_EQ(parseQuantity("0941))))"), 941);
    ASSERT_EQ(parseQuantity("1234567-9"), 1234567);
    ASSERT_EQ(parseQuantity("214748364!6"), 214748364);
}

TEST(parseQuantity, parsingInvalidData) {
    ASSERT_EQ(parseQuantity("asd"), 0);
    ASSERT_EQ(parseQuantity(""), 0);
    ASSERT_EQ(parseQuantity("a12"), 0);
    ASSERT_EQ(parseQuantity("  1"), 0);
    ASSERT_EQ(parseQuantity("!@#1345"), 0);
    ASSERT_EQ(parseQuantity("as234d"), 0);
}

TEST(parseQuantity, parsingCorrectNumber) {
    ASSERT_EQ(parseQuantity("42"), 42);
    ASSERT_EQ(parseQuantity("1410"), 1'410);
    ASSERT_EQ(parseQuantity("873591872"), 873'591'872);
    ASSERT_EQ(parseQuantity("123456789"), 123'456'789);
    ASSERT_EQ(parseQuantity("987654321"), 987'654'321);
    ASSERT_EQ(parseQuantity("2147483646"), 2'147'483'646);
}

TEST(parseQuantity, parsingTheMaximumNumber) {
    ASSERT_EQ(parseQuantity("2147483647"), INT_MAX);
}

TEST(parseQuantity, parsingTooLargeANumber) {
    ASSERT_EQ(parseQuantity("2147483648"), 214'748'364);
    ASSERT_EQ(parseQuantity("2147493647"), 214'749'364);
    ASSERT_EQ(parseQuantity("9197488642"), 919'748'864);
    ASSERT_EQ(parseQuantity("5643213425617631"), 564'321'342);
    ASSERT_EQ(parseQuantity("87184511779177197"), 871'845'117);
}
