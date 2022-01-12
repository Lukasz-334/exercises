#pragma once
#include <initializer_list>
#include <iostream>

template <typename T>
class vector {
    int size;
    T* wsk;
   

public:
 static int numberOfObjects;
    vector()
        : size(0), wsk{nullptr}{
        numberOfObjects++;
    };

    vector(int s)
        : size(s)
    {
        for (int i = 0; i < s; i++) {
            wsk[i] = 0;
        }
    }

    vector(std::initializer_list<T>lst)
        : size{lst.size()},
          wsk{new T[size]} {
        std::copy(lst.begin(), lst.end(), wsk);
    }

    ~vector() {
        delete[] wsk;
        numberOfObjects--;
    }
};
template<typename T>
int vector<T>::numberOfObjects=0;