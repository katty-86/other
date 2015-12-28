#include <iostream>
#include <vector>

int sum_divisors(int a);

int main(){

        std::vector<int> v= {21, 111, 112, 220, 69, 134, 85,6};
        for (int i: v){
                int sd=0;
                sd=sum_divisors(i);
                if (sd > 2*i){

                        std::cout<<i<<" abundant by "<<sd-2*i<<std::endl;
                }
                else if(sd < 2*i){
                        std::cout<<i<<" deficient"<<std::endl;
                }
                else{
                        std::cout<<i <<" ~~neither~~ deficient"<<std::endl;
                }
        }
        return 0;
}

int sum_divisors(int a){
        int sum=0;
        for (int i=1; i<=a; ++i){
                int mod=a%i;
                if(mod==0){
                        sum+=i;
                }
        }
        return sum;
}
