//============================================================================
// Name        : cpp.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <random>
#include <string>
#include <sstream>
#include <chrono>
#include <algorithm>

using namespace std;

char returnLetter(const char &s){
	//unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
	std::random_device  seed;
	std::default_random_engine e(seed());
	string vowels="aeiou";
	string consonants="bdfghjklmnpqrstwxyz";
	if(s=='c'){
		uniform_int_distribution<int>distr(0, consonants.size()-1);
		return consonants.at(distr(e));
	}
	else if (s=='v'){
		uniform_int_distribution<int>distr(0, vowels.size()-1);
		return vowels.at(distr(e));
	}
	else{
		return s;
	}
}


int main() {

	string data_="cvcvcc CcvV cvcvcvcvcvcvcvcvcvcv";
	transform(data_.begin(), data_.end(), data_.begin(), [](char c) {return returnLetter(tolower(c));});
	cout<<data_<<endl;


	return 0;
}
