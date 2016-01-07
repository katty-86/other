//============================================================================
// Name        : t_237e.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <fstream>
#include <list>
using namespace std;


bool writeWordFromFileToList( list<string> &l, string file){
	  string line;
	  ifstream myfile (file);
	  if(myfile.is_open()){
		  while(getline(myfile,line)){
			  l.push_back(line);
			  if(line.find('\n') !=std::string::npos){
				  cout<<"true"<<endl;
			  }
		  }
		  return true;
	  }
	  else{
		  cout<<"unable to open file"<<endl;
		  return false;
	  }

}

string findLongestWord(const list<string> &l, const string &s){
	string longestWord="";
	for(auto &it: l){
		if(it.find_first_not_of(s) ==std::string::npos){
				if(it.size()>longestWord.size()){
					longestWord=it;
				}
		}
	}

	return longestWord;
}


int main() {
	list<string> wordlist;
	//string filename="/usr/share/dict/words";
	string filename="t_237e_enable1.txt";
	if(writeWordFromFileToList(wordlist,filename)==true){
		int number;
		cout<<"Amount of test: "<<endl;
		cin>>number;
		vector <string> v(number);
		for(int i=0; i<number; i++){
			string letters;
			cin>>letters;
			v.at(i)=letters;
		}
		for(int i=0; i<number; i++){
		cout<<v.at(i)<<" = "<<findLongestWord(wordlist, v.at(i))<<endl;
		}
	}
	else{
		cout<<"Problem reading file"<<endl;
	}



}
