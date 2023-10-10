#include "parseQuantity.hpp"

int parseQuantity(const char* str) {
    std::string number;
    long long parsed_number = 0;

    for (int i = 1; i <= 10; i++) {
        if (std::isdigit(*str)) {
            number += *str;
            str++;
        } else {
            break;
        }
    }

    if (number.empty()) {
        return 0;
    }

    parsed_number = std::stoll(number);
    if (parsed_number <= INT_MAX) {
        return static_cast<int>(parsed_number);
    }
    number.erase(9);
    return std::stoi(number);
}
