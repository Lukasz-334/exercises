#include "vector_v2.hpp"


int main(){


vector<int>v{1,2,3,4,5};

vector<int>w=v;
//int j=0;
/*
for(size_t i=0;i<w.size();i++){

    std::cout<<w[j];
    j++;
    
}
*/
v[0]=234;
std::cout<<v[0];


    return 0;
}
