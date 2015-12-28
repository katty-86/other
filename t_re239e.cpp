#include <iostream>

int main(){

	int number;
	std::cout<<"podaj liczbe" <<std::endl;
	std::cin>>number;
	while(number!=1){
	
		if(number%3==2){
			std::cout<<number<<" +1"<<std::endl;
			number++;
		}
		else if(number%3==1){
			std::cout<<number<<" -1"<<std::endl;
			number--;

		}
		else {
			std::cout<<number<<std::endl;
		}
		number/=3;
	
	}

	std::cout<<number<<std::endl;

}
