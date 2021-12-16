#include "gtest/gtest.h"
#include "remove.hpp"
#include "string"

TEST(numbres, TestOfNumbers) {
    std::vector<int> v1{1, 6, 2, 7, 7, 5};
    std::vector<int> v2 = v1;
    remove_v2(v1.begin(), v1.end(), 2);
    remove(v2.begin(), v2.end(), 2);

    ASSERT_EQ(v1, v2);
}

TEST(iterator, IteratorTest) {
    std::vector<int> v1{2,2,3};
    std::vector<int> v2 = v1;
    auto it1 = remove_v2(v1.begin(), v1.end(), 2);
    auto it2 = remove(v2.begin(), v2.end(), 2);

    ASSERT_EQ(*it1, *it2);
}

TEST(string, SentenceTest) {

    std::string str1="ababab";
    std::string str2=str1;


    remove_v2(str1.begin(),str1.end(),'a');
    remove(str2.begin(),str2.end(),'a');

    ASSERT_EQ(str1,str2);


}