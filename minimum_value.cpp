#include <iostream>
#include <vector>

template <typename T>
int minimalValue(const std::vector<T>& vec) {
    for (size_t i = 1; i < vec.size(); i++) {
        if (vec[i - 1] < vec[i]) {
            return i - 1;
        }
    }
    return vec.size();
}

int main() {
    std::vector<int> vecInt = {3, 2, 1, 6, 7, 8};
    std::vector<char> vecChar = {'d', 'c', 'a', 'f', 'g', 'h'};

    std::cout << minimalValue(vecInt) << std::endl;
    std::cout << minimalValue(vecChar) << std::endl;

    return 0;
}

