#include <string>
#include "parseQuantity.hpp"

int parseQuantity(const char* str) {
    std::string number;

    while (std::isdigit(*str)) {
        number += *str;
        str++;
    }

    if (number.empty()) {
        return 0;
    }
    return std::stoi(number);
}
