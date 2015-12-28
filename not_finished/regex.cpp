//============================================================================
// Name        : regex.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <regex>
#include <string>
#include <algorithm>
#include "SQL.h"

using namespace std;


int main() {
	for (;;) {
		string str;
		cout << "podaj string" << endl; // prints !!!Hello World!!!
		getline(cin, str);
		SQL sql;
		sql.readSQL(str, "COS");
		cout<<"-----------\n";
		sql.printAll();
	}
	return 0;
}




