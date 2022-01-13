
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v{3, 7, 8, 2, 19, 15, 11, 4};

    std::sort(v.begin(), v.end(), [](int x, int y) {
        if ((x % 2 == 0) && (y % 2 == 0)) {
            return x < y;
        } else if ((x % 2 == 0) && (y % 2 != 0)) {
            return true;
        } else if ((x % 2 != 0) && (y % 2 == 0)) {
            return false;
        } else {
            return x < y;
        }
    });

    std::vector<int> v2{3, 7, 8, 2, 19, 15, 11, 4};
    std::sort(v2.begin(), v2.end());
    std::stable_partition(v.begin(), v.end(), [](int x) { return x % 2 == 0; });

    std::cout << "first version" << std::endl;
    for (auto el : v) {
        std::cout << el << " ";
    }
    std::cout << std::endl;
    std::cout << "second version" << std::endl;
    for (auto el : v) {
        std::cout << el << " ";
    }
    std::cout << std::endl;

    return 0;
}
