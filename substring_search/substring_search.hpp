#include <iostream>
#include <string>

template <typename T1, typename T2>
bool search(T1 substring, T2 string) {
    if ((substring.size() == 0) || (string.size() == 0)) {
        return false;
    }

    size_t count = 0;
    size_t string_size = string.size() - substring.size() + 1;

    for (size_t j = 0; j <= string_size; j++) {
        for (size_t i = 0; i < substring.size(); i++) {
            if (string[j] == substring[i]) {
                count++;
                j++;

            } else {
                count = 0;
                break;
            }
        }

        if (count == substring.size()) {
            return true;
        }
    }
    return false;
}
