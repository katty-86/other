#include <iostream>
#include <vector>
#include <string>

//todo: brakuje pomijania spacji-jak nie poprawny format -> coredump!
int sum_div(int a);

int main(){

	std::vector <std::string> pairs;
	int number;
	std::cout<<"podaj liczbe par" <<std::endl;
	std::cin>>number;
	std::vector<std::string> result(number); 
	for( int i= 0; i<number; ++i){
		std::string elem;
		std::cin>>elem;
		pairs.push_back(elem);
	}

	for (int i=0; i<number; i++){
		int l1, l2, sum1, sum2;
		std::size_t pos1 = pairs[i].find(",");
		std::size_t pos2 = pairs[i].find(")");  
		l1= std::stoi(pairs[i].substr(1,pos1-1));
		l2= std::stoi(pairs[i].substr(pos1+1, pos2-pos1-1));
		sum1=sum_div(l1);
		sum2=sum_div(l2);
		std::cout<<"suma "<< sum1<<" "<<sum2<<std::endl;
		result[i]=((sum1==sum2) ? "VALID" : "NOT VALID");
	}

	for (int i=0; i<number; i++){
		std::cout<<pairs[i]<<" "<<result[i]<<std::endl;
	}

}

int sum_div(int a){
	int sum=0, i=2;
	while((a!=1) && (i<=a)){
		if(a%i==0){
			a/=i;
			sum+=i;
		}
		i++;
	} 
	return sum;
}

