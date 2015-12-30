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
	PersonalDate(const PersonalDate &p) {
		name = p.name;
		surname = p.surname;
	}
	void print() {
		std::cout << surname << " " << name << "---";
	}
	string getPersonalDate() {
		return name + "(" + to_string(surname) + ")";
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

void shuffleFirstVersion(std::vector<PersonalDate> vp) {
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	int attempt = 0;
	bool flag_end;
	do {
		++attempt;
		int i = 1;
		flag_end = false;
		shuffle(vp.begin(), vp.end(), std::default_random_engine(seed));
		auto it = vp.begin();
		while ((it != vp.end()) && (flag_end == false)) { //&& (flag_end!=true) ))) {
			if (it == vp.begin()) {
				//	cout<<i<<" "<<(*it).getPersonalDate()<<" "<<vp.back().getPersonalDate()<<endl;
				flag_end = checkIfFamily(*it, vp.back());
			} else {
				auto prev = it - 1;
				flag_end = checkIfFamily(*it, *prev);
				//	cout<<i<<" "<<(*it).getPersonalDate()<<" "<<(*prev).getPersonalDate()<<endl;
			}
			++it;
			++i;
		}
	} while (flag_end == true);

	auto prev = vp.begin();
	int i = 1;
	for (auto it = vp.begin() + 1; it != vp.end(); ++it) {
		cout << i << " " << (*prev).getPersonalDate() << " "
				<< (*it).getPersonalDate() << endl;
		i++;
		prev++;
	}
	cout << i << " " << (*prev).getPersonalDate() << " "
			<< (*vp.begin()).getPersonalDate() << endl;
	cout << "\t*Amount of attempt  " << attempt <<"\n"<< endl;
}

void shuffleSecondVersion(std::vector<PersonalDate> vp) {
	std::vector<pair<PersonalDate, PersonalDate>> pair;
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	shuffle(vp.begin(), vp.end(), std::default_random_engine(seed));
	for (auto it = vp.begin() + 1; it != vp.end(); ++it) {
		auto prev = it - 1;
		auto next = it;
		while (checkIfFamily(*it, *prev)) {
			++next;
			if (next == vp.end()) {
				next = vp.begin();
			}
			iter_swap(it, next);
		}

	}
	auto prev = vp.begin();
	int i = 1;
	for (auto it = vp.begin() + 1; it != vp.end(); ++it) {
		cout << i << " " << (*prev).getPersonalDate() << " "
				<< (*it).getPersonalDate() << endl;
		i++;
		prev++;
	}
	cout << i << " " << (*prev).getPersonalDate() << " "
			<< (*vp.begin()).getPersonalDate() << endl;

}

int main() {

	cout << "\t*Prog name " << __FILE__ << "\n";
	cout << "\t*Date " << __DATE__ << " " << __TIME__ << "\n";
	cout << "\t*line " << __LINE__ << endl;

	std::vector<PersonalDate> vp;
	vp = readFromFile("data_247e.txt");
	shuffleFirstVersion(vp);
	shuffleSecondVersion(vp);

}

