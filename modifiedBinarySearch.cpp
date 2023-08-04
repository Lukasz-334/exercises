#include <iostream>
#include <iterator>
#include <vector>

template <typename T>
int modifiedBinarySearch(const std::vector<T>& vec) {
    auto it_begin = vec.begin();
    auto it_end = vec.end() - 1;
    auto it_center = it_begin + (vec.size() / 2);

    while ((it_begin < it_center) && (it_center < it_end)) {
        if (*it_center < *(it_center - 1)) {
            it_begin = it_center;
            it_center = it_center + ((std::abs(it_begin - it_end) / 2));

        } else {
            it_end = it_center;
            it_center = it_center - ((std::abs(it_begin - it_end) / 2));
        }
    }
    return std::distance(vec.begin(), it_center);
}

int main() {
    std::vector<int> decreasing_and_then_increasing_values  = {30, 25, 21, 20, 19, 15, 14, 12, 9, 8, 7, 6, 5, 6, 7, 8, 12, 14, 15, 15, 17}; 
    std::cout <<"critical value index "<< modifiedBinarySearch(decreasing_and_then_increasing_values);
    
    std::cout << std::endl;
    
    decreasing_and_then_increasing_values = {'z', 'f', 'd', 'c', 'a', 'f', 'g', 'h', 'i', 'j'};
    std::cout <<"critical value index "<< modifiedBinarySearch(decreasing_and_then_increasing_values);
 
   

    return 0;
}

