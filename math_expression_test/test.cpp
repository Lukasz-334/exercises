#include "gtest/gtest.h"
#include "mathExpression.hpp"

TEST(mathExpressionTest, correctUseOfParentheses) {
    std::string t_one = "2*((4+3)-(2/4))";
    std::string t_two = "7*(1+3))";
    std::string t_three = ")7*2)";
    std::string t_four = "(";
    std::string t_five = ")";

    ASSERT_EQ(mathExpressionTest(t_one), true);
    ASSERT_EQ(mathExpressionTest(t_two), false);
    ASSERT_EQ(mathExpressionTest(t_three), false);
    ASSERT_EQ(mathExpressionTest(t_four), false);
    ASSERT_EQ(mathExpressionTest(t_five), false);
}

