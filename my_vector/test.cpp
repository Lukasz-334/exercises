#include "gtest/gtest.h"
#include "vector_v2.hpp"


TEST(DefaultConstructor, constructorTest ) {
 
vector<int>v;
 
ASSERT_EQ(v.numberOfObjects, 1);
   
}
TEST(Constructor,checksTheNumberOfElementsInTheConstructor ) {
 
vector<int>v2(5);
 
ASSERT_EQ(v2.size(), 5);
   
}
