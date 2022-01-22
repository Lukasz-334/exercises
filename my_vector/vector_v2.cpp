#include "vector_v2.hpp"


int main(){


vector<int>v{1,5,5};


try{
v.at(5);

}catch(std::out_of_range const & re){
    std::cout<<"wyj złap";
   std::cout<<re.what();

}




    return 0;
}
