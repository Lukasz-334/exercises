#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

template <typename T>
void reverse(T& container) {
    auto begin_it = container.begin();
    auto end_it = container.end() - 1;

    while (begin_it < end_it) {
        std::swap(*begin_it, *end_it);
        begin_it++;
        end_it--;
    }
}

int main() {
    std::vector<int> vec{1, 2, 3, 4, 5};

    reverse(vec);

    for (auto el : vec) {
        std::cout << el << ' ';
    }
}
