#pragma once
#include <algorithm>


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
