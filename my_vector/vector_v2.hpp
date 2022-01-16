#pragma once
#include <initializer_list>
#include <iostream>

template <typename T>
class vector {
public:
    size_t size_;
    T* wsk;

public:
    static int numberOfObjects;
    vector()
        : size_(0), wsk{nullptr} {
        numberOfObjects++;
    };

    vector(int s)
        : size_(s),
          wsk{new T[s]} {
        for (int i = 0; i < s; i++) {
            wsk[i] = 0;
        }
    }

    vector(const vector& vec)
        : size_(vec.size()),

          wsk{new T[size_]} {
        for (size_t i = 0; i < size_; i++) {
            wsk[i] = vec.wsk[i];
        }
    }

    vector& operator=(const vector& vec) {
        if (&vec != this) {
            delete[] wsk;
            size_ = vec.size();
            wsk = new T[size_];
            for (size_t i = 0; i < size_; i++) {
                wsk[i] = vec.wsk[i];
            }
        }
        return *this;
    }
    vector(std::initializer_list<T> lst)
        : size_{lst.size()},
          wsk{new T[size_]} {
        std::copy(lst.begin(), lst.end(), wsk);
    }

    size_t size() const {
        return size_;
    }

    T& operator[](int el) {
        return wsk[el];
    }

    ~vector() {
        delete[] wsk;
        numberOfObjects--;
    }
};
template <typename T>
int vector<T>::numberOfObjects = 0;