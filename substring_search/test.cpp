#include "gtest/gtest.h"
#include "substring_search.hpp"

TEST(substring , findingASubstring ) {
    std::string substring = "12";
    std::string string = "12345678";

    ASSERT_EQ(search(substring,string),true);
    
    substring = "78";
    ASSERT_EQ(search(substring,string),true); 
    substring = "3";
    ASSERT_EQ(search(substring,string),true); 

    substring = "sentence";
    string = "test sentence";
    ASSERT_EQ(search(substring,string),true); 
    
    substring = "ce";
    ASSERT_EQ(search(substring,string),true); 
}

TEST(substring , SubstringNotFound ) {
    std::string substring = "tesx";
    std::string string = "test sentence";

    ASSERT_EQ(search(substring,string),false);
    
    substring = "santance";
    ASSERT_EQ(search(substring,string),false); 
    substring = "tast";
    ASSERT_EQ(search(substring,string),false); 
    
}

