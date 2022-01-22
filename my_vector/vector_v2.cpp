#include "vector_v2.hpp"


int main(){


vector<int>v{1,5,5};


try{
std::cout<<v.at(2);

}catch(std::out_of_range const & re){
  
   std::cout<<re.what();

}




    return 0;
}
