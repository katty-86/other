//============================================================================
// Name        : t_236e.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <algorithm>
#include <chrono>       // std::chrono::system_clock
#include <random>

using namespace std;

int main() {
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	int pieces=50;
	string tertromino ="0ISZLJT";
	string output="";
	int val=tertromino.size();
	int remainder=pieces%val;
	int div=pieces/val;
	for (int i=0; i<div; i++){
		shuffle(tertromino.begin(), tertromino.end(), std::default_random_engine(seed));
		output.append(tertromino);
	}
	shuffle(tertromino.begin(), tertromino.end(), std::default_random_engine(seed));
	output.append(tertromino.substr(0,remainder));
	cout<<"\n"<<output<<endl;
}
