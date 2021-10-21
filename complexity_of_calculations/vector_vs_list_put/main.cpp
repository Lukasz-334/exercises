#include <chrono>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>
#include <string>


template<typename T>
void test_vector(std::vector<T>&v) {
    
    auto it = v.begin() + (v.size() / 2);
    v.insert(it, T());
}

template<typename T>
void list_test(std::list<T>& l) {
   
    auto it = l.begin();
    std::advance(it, l.size() / 2);

    l.insert(it, T());
}

int main() {
    
    std::vector<std::string> vec(10'000'000,"abc");
    vec.reserve(11'000'000);

    std::list<std::string> ls(10'000'000, "abc");

    auto start = std::chrono::steady_clock::now();

    test_vector(vec);

    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> vector_time = end - start;
    std::cout << "vector_time " << vector_time.count() << "s\n";

    auto start_ = std::chrono::steady_clock::now();

    list_test(ls);

    auto end_ = std::chrono::steady_clock::now();
    std::chrono::duration<double> list_time = end_ - start_;
    std::cout << "list_time " << list_time.count() << "s\n";

    return 0;
}

