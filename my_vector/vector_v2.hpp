#pragma once
#include <initializer_list>
#include <iostream>

template <typename T>
class vector {
    size_t size_;
    T* wsk;
   

public:
 static int numberOfObjects;
    vector()
        : size_(0), wsk{nullptr}{
        numberOfObjects++;
    };

    vector(int s)
        : size_(s),
        wsk{new T[s]}
    {
        for (int i = 0; i < s; i++) {
            wsk[i] = 0;
        }
    }

    vector(std::initializer_list<T>lst)
        : size_{lst.size()},
          wsk{new T[size_]} {
        std::copy(lst.begin(), lst.end(), wsk);
    }

    size_t size() const {
        return size_;
    }

    ~vector() {
        delete[] wsk;
        numberOfObjects--;
    }
};
template<typename T>
int vector<T>::numberOfObjects=0;