#include<string>
#include<vector>
#include "mathExpression.hpp"


bool mathExpressionTest(const std::string& expression) {
    std::vector<char> stack;

    for (size_t i = 0; i < expression.size(); i++) {
        if (expression[i] == '(') {
            stack.push_back('(');
        } else if ((expression[i] == ')') && (stack.size() != 0)) {
            stack.pop_back();
        } else if ((expression[i] == ')') && (stack.size() == 0)) {
            return false;
        }
    }

    return stack.size() == 0;
}
