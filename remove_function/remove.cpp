#include <algorithm>
#include <iostream>
#include <vector>

template <typename iterator, typename Type>
iterator remove_v2(iterator begin, iterator end, const Type& value) {
    iterator find_iter = find(begin, end, value);

    if (find_iter != end) {
        for (iterator it = find_iter; it != end; it++) {
            if (*it != value) {
                *find_iter = std::move(*it);
                find_iter++;
            }
        }
    }
    return find_iter;
}

int main() {
    std::vector<int> v{1, 6, 2, 7, 7, 5};
    auto it = remove_v2(v.begin(), v.end(), 2);

    for (auto x : v) {
        std::cout << x << ' ';
    }

    std::cout<<std::endl;

    return 0;
}
