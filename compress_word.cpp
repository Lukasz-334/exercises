#include <algorithm>
#include <iostream>
#include <string>

bool eraseWord(std::string& word_to_delete, int word_length) {
    for (size_t i = 0; i < word_to_delete.size(); i++) {
        auto it = std::search_n(word_to_delete.begin(), word_to_delete.end(), word_length, word_to_delete[i]);

        if (it != word_to_delete.end()) {
            word_to_delete.erase(it, it + word_length);
            return true;
        }
    }
    return false;
}

std::string compressWord(std::string str, int word_length) {
    while (eraseWord(str, word_length)) {
    }
    return str;
}

int main() {
    std::string str = "abccccccdeeeeeefiiiiiig";
    int word_length = 3;

    auto compress_word =  compressWord(str, word_length);
    std::cout << compress_word << std::endl;
    

    return 0;
}
