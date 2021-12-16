#include "remove.hpp"
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v{1, 6, 2, 7, 7, 5};
    auto it = remove_v2(v.begin(), v.end(), 2);

    for (auto x : v) {
        std::cout << x << ' ';
    }

    std::cout << std::endl;
    std::cout << *it << std::endl;

    std::string str1="ababab";
   remove_v2(str1.begin(),str1.end(),'a');

   std::cout<<str1<<std::endl;


    return 0;
}
