#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <regex>
#include <algorithm>
#include <random>
#include <chrono>       // std::chrono::system_clock

using namespace std;

struct PersonalDate {
	std::string name;
	int surname;
	PersonalDate(std::string n, int s) :
			name(n), surname(s) {
	}
	void print() {
		std::cout << surname << " " << name << "---";
	}
};

bool checkIfFamily(PersonalDate a, PersonalDate b) {
	return a.surname == b.surname ? true : false;
}
std::vector<PersonalDate> readFromFile(std::string filename) {
	std::vector<PersonalDate> lp;
	ifstream myfile;
	myfile.open(filename);
	std::string line;
	int surname = 1;

	if (myfile.is_open()) {
		while (getline(myfile, line)) {
			std::regex e("([[:w:]]+)[[:s:]]*");
			std::sregex_iterator pos_u(line.cbegin(), line.cend(), e);
			std::sregex_iterator end_u;
			for (; pos_u != end_u; pos_u++) {
				lp.push_back(PersonalDate(pos_u->str(1), surname));
			}
			surname++;
		}
	} else {
		std::cout << "unable to open file" << endl;
	}

	return lp;

}

int main() {

	std::vector<PersonalDate> vp, vp2;
	vp = readFromFile("data_247e.txt");
	std::cout << "---" << std::endl;
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	/*	for (auto it = vp.begin(); it != vp.end(); ++it) {

	 (*it).print();
	 }*/
	vp2 = vp;

	int i = 0;
	std::cout << "---" << std::endl;
	/*auto it_vp2= vp2.begin();
	 for (auto it = vp.begin(); it != vp.end(); ++it) {
	 cout<<i<<" ";
	 (*it).print();
	 (*it_vp2).print();
	 cout<<endl;
	 ++it_vp2;
	 ++i;
	 }*/
	std::cout << "---" << std::endl;
	auto it_vp2 = ++vp.begin();
	i = 1;
	//++it_vp2;

	bool flag_end ;
	do {
		flag_end = false;
		shuffle(vp.begin(), vp.end(), std::default_random_engine(seed));
		auto it = vp.begin();
		int i=1;
		while((it != vp.end()) && (flag_end==false)) {//&& (flag_end!=true) ))) {
			if (it == vp.begin()) {
				cout<<i<<" ";
				(*it).print();
				vp.back().print();
				flag_end=checkIfFamily(*it, vp.back());
				cout << "pierwszy " << flag_end<<endl;
			} else {
				auto it2=it;
				it2--;
				flag_end=checkIfFamily(*it, *it2);
				cout<<i<<" ";
				(*it).print();
				(*it2).print();
				cout << "reszta " <<flag_end<< endl;
			}
			++it;
			++i;
		}
		cout<<endl;
	} while (flag_end == true);

//	cout<<"koncze??0"<<endl;

	/*	for (auto it = vp.begin(); it != vp.end()-1; ++it) {
	 cout<<i<<" ";
	 (*it).print();
	 (*it_vp2).print();

	 if(!checkIfFamily(*it, *it_vp2)){
	 cout<<"ok"<<endl;
	 }
	 ++it_vp2;
	 cout<<endl;
	 ++i;
	 }

	 auto it=vp.begin();
	 it_vp2=vp.end()-1;
	 cout<<i<<"--> " ;
	 (*it_vp2).print();
	 (*it).print(); */

}

