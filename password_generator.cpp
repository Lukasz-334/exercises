#include <algorithm>
#include <iostream>
#include <random>
#include <string>
#include <utility>

template <typename T>
T randomGenerator(T begin, T end) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<char> distrib(begin, end);
    return distrib(gen);
}

std::string password_gen() {
    std::string generatedPassword;
    std::pair<char, char> dataRanges[3]{
        {'a', 'z'},
        {'A', 'Z'},
        {'0', '9'},
    };
    size_t passwordLength = randomGenerator(8, 8);

    generatedPassword += randomGenerator('a', 'z');
    generatedPassword += randomGenerator('0', '9');
    generatedPassword += randomGenerator('A', 'Z');
    generatedPassword += randomGenerator(33, 38);

    while (generatedPassword.size() < passwordLength) {
        int j = randomGenerator(0, 2);
        char s = randomGenerator(dataRanges[j].first, dataRanges[j].second);

        if (std::string::npos == generatedPassword.find(s)) {
            generatedPassword += s;
        }
    }
    std::random_shuffle(generatedPassword.begin(), generatedPassword.end());
    return generatedPassword;
}

int main() { 
    
std::cout << password_gen() << std::endl;

}
