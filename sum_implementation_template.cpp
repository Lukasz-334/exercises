#include <cmath>
#include <cstdint>
#include <iostream>
#include <type_traits>

template <typename T1, typename T2>
auto sum(const T1 lhs, const T2 rhs) -> decltype(lhs + rhs) {
    return lhs + rhs;
}

template <typename T1, typename T2, typename T3>
void Test(const T1 lhs, const T2 rhs, const T3 result) {
    auto resultSum = sum(lhs, rhs);
    if (std::is_floating_point<T3>::value) {
        resultSum = std::round(resultSum * 10) / 10.0;
    }

    if (resultSum != result) {
        std::cout << "Wrong " << lhs << " + " << rhs << " != " << result << " (" << resultSum << ")" << std::endl;
    }
}

int main() {
    {
        int lhs = 7;
        int rhs = 8;
        int result = 15;

        Test(lhs, rhs, result);
    }

    {
        double lhs = 10.2;
        double rhs = 12.6;
        double result = 22.8;

        Test(lhs, rhs, result);
    }

    {
        uint8_t lhs = 210;
        uint8_t rhs = 180;
        uint16_t result = 390;

        Test(lhs, rhs, result);
    }

    {
        uint16_t lhs = 12210;
        uint8_t rhs = 180;
        uint16_t result = 12390;

        Test(lhs, rhs, result);
    }

    return 0;
}
