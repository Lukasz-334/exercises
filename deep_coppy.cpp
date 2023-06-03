#include <iostream>
#include <memory>
#include <vector>

struct Base {
    explicit Base(const int i = 0)
        : a{i} {
    }

    virtual bool equals(const std::shared_ptr<Base>& other) const {
        return other->a == this->a;
    }

    virtual std::shared_ptr<Base> coppy() const {
        return std::make_shared<Base>(*this);
    }

    virtual ~Base() {
    }

    int a;
};

struct Derived1 : public Base {
    explicit Derived1(const int i = 0)
        : b{i} {
    }

    bool equals(const std::shared_ptr<Base>& other) const override {
        if (std::shared_ptr<Derived1> ptr = std::dynamic_pointer_cast<Derived1>(other); ptr != nullptr) {
            return ptr->b == this->b && Base::equals(other);
        }
        return false;
    }

    std::shared_ptr<Base> coppy() const override {
        return std::make_shared<Derived1>(*this);
    }

    int b;
};

struct Derived2 : public Base {
    explicit Derived2(const int i = 0)
        : c{i} {
    }

    bool equals(const std::shared_ptr<Base>& other) const override {
        if (std::shared_ptr<Derived2> ptr = std::dynamic_pointer_cast<Derived2>(other); ptr != nullptr) {
            return ptr->c == this->c && Base::equals(other);
        }
        return false;
    }

    std::shared_ptr<Base> coppy() const override {
        return std::make_shared<Derived2>(*this);
    }

    int c;
};

std::vector<std::shared_ptr<Base>> deep_copy(const std::vector<std::shared_ptr<Base>>& original) {
    std::vector<std::shared_ptr<Base>> copyVector;

    for (const auto& obj : original) {
        copyVector.push_back(obj->coppy());
    }

    return copyVector;
}

int main() {
    std::vector<std::shared_ptr<Base>> vec;
    vec.push_back(std::make_shared<Base>(2));
    vec.push_back(std::make_shared<Derived1>(5));
    vec.push_back(std::make_shared<Derived2>(7));
    vec[1]->a = 3;

    std::vector<std::shared_ptr<Base>> vec2 = deep_copy(vec);

    if (vec.size() != vec2.size()) {
        std::cout << "false size" << std::endl;
    } else {
        for (size_t i = 0; i < vec.size(); ++i) {
            if (vec[i] == vec2[i] || !vec[i]->equals(vec2[i]))
                std::cout << "false at " << i << std::endl;
        }
    }

    return 0;
}
