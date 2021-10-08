#include <iostream>
#include <string>
#include <vector>

class MyString {
public:
    MyString() = default;
    MyString(const char* sentence)
        : str_(sentence) {
        lenght_ = strlen(str_);
    };

    std::size_t strlen(const char* begin) {
        size_t lenght = 0;
        while (*begin != '\0') {
            begin++;
            lenght++;
        }
        return lenght;
    }

    void print() {
        if (!lenght_) {
            std::cout << "empty string";
        } else {
            std::cout << str_;
        }
    }

    size_t len() {
        return lenght_;
    }

    void set(const char* new_string) {
        str_ = new_string;
        lenght_ = strlen(str_);
    }

private:
    const char* str_;
    size_t lenght_ = 0;
};

int main() {
    MyString a;
    a.print();
    std::cout << a.len() << "\n";
    MyString b("example");
    b.print();
    std::cout << b.len() << "\n";
    b.set("qwertyuiop");
    b.print();
    std::cout << b.len() << "\n";
    std::cout << "end of program\n";

    return 0;
}