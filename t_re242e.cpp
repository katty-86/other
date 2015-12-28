#include <iostream>


int main(){
    
    int fruits=0,people,weak=1, plants;
    std::cin>>people>>plants;
    
   while(fruits<people){
    
  	 plants+=fruits;
   	 fruits+=plants;
   	 weak++;
   	 std::cout<<"fruit "<<fruits<<" plant "<<plants<<std::endl; 
    }
    std::cout<<""<<weak<<std::endl;   
    return 0;
}

