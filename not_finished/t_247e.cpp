#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <regex>

struct PersonalDate{
	string imie;
	char nazwisko;
}

std::vector<PersonalDate> readFromFile(std::string filename){
std::vector<PersonalData> lp;
ifstream myfile;
myfile.open(filename);
std::string line;

if(myfile.is_open|()){
	while(getline(myfile, line)){
		std::regex e("([[:w:]]+)[[:s:]]*");
	std::sregex_iterator pos_u(str.cbegin(), str.cend(), e);
	std::sregex_iterator end_u;
	for (; pos_u != end_u; pos_u++) {
		std::cout << pos_u->str() << "^^^^^" << pos_u->str(1) << "----"
				<< pos_u->str(2) << std::endl;

		lp.push_back(PersonalData);
	}	
	}
}
else{
	std::cout<<"unable to open file"<<endl;
}



}



