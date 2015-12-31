//============================================================================
// Name        : t_246i.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <map>
#include <vector>
#include <memory>
using namespace std;

const int ascii_before_a = 64;
map<int, char> dic;

map<int, char> initDictionary() {
	map<int, char> dictionary;

	for (int i = 1; i <= 26; i++) {
		dictionary[i] = ascii_before_a + i;
	}

	return dictionary;
}

void print(const map<int, char> &dictionary) {

	for (auto &it : dictionary) {
		cout << it.first << " " << it.second << endl;
	}
}

void findLetter(string digit, string letter, int dpos, int lpos) {
	if (dpos == (digit.size())) {
		cout << letter << endl;
		return;
	}
	//one letter
	int single = stoi(digit.substr(dpos, 1));
	if(single!=0){
		char s=dic[single];
		letter.push_back(s);
		findLetter(digit, letter, dpos + 1, lpos + 1);
	}

	//double letter
	if (dpos < (digit.size() - 1)) {
		int s_double = stoi(digit.substr(dpos, 2));
		if (s_double < 26) {
			char s=dic[s_double];
			letter.push_back(s);
			letter.append(",");
			findLetter(digit, letter, dpos + 2, lpos + 1);
		}

	}
}

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	dic = initDictionary();
//print(dic);

	string tekst = "1234";
	string let;
	findLetter(tekst, let, 0, 0);

	return 0;
}
