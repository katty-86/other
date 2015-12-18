//============================================================================
// Name        : Ggggggggggg.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <map>
#include <cstring>
#include <cctype>

using namespace std;

map<char, string> builDictionaryPL_GG(string s);
map<char, string> builDictionaryPL_GG(const map<char, string> &p_gg);
map<string, char> builDictionaryGG_PL(const map<char, string> &p_gg);
string encodeGGGG(const map<char, string> &vec, string s);
string decodeGGGG(const map<string, char> &vec, string s);

int main() {

	map<char, string> mpl_gg;
	map<string, char> mgg_pl;
	string enc_result, dec_result;
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	string dictionary = "H GgG d gGg e ggG l GGg o gGG r Ggg w ggg";
	string gg_words = "GgGggGGGgGGggGG, ggggGGGggGGggGg!";
	mpl_gg = builDictionaryPL_GG(dictionary);
	enc_result = encodeGGGG(mpl_gg, "Hello, world!");
	cout << enc_result << endl;
	cout << "decode" << endl;
	mgg_pl = builDictionaryGG_PL(mpl_gg);
	dec_result = decodeGGGG(mgg_pl, gg_words);
	cout << dec_result << endl;
	return 0;
}

map<char, string> builDictionaryPL_GG(string s) {

	map<char, string> lex_pair;
	int pos = 0;
	do {
		char key_type;
		string value_type;
		pos = s.find(" ");
		key_type = (s.substr(0, pos)).at(0);
		s.erase(0, pos + 1);
		pos = s.find(" ");
		value_type = s.substr(0, pos);
		s.erase(0, pos + 1);
		lex_pair.insert(pair<char, string>(key_type, value_type));
	} while (pos != -1);

	return lex_pair;
}

string encodeGGGG(const map<char, string> &vec, string s) {
	string s_result;
	int charAmount = s.length() + 1;
	char *tabChar = new char[charAmount];
	strcpy(tabChar, s.c_str());
	for (int i = 0; i < charAmount; ++i) {
		if (isalpha(tabChar[i])) {
			string value = vec.find(tabChar[i])->second;
			s_result.append(value);
		} else {
			s_result.push_back(tabChar[i]);
		}

	}
	delete[] tabChar;
	return s_result;
}

string decodeGGGG(const map<string, char> &vec, string s) {
	string s_result;
	int charAmount = s.length() + 1;
	char *tabChar = new char[charAmount];
	strcpy(tabChar, s.c_str());

	string word = "";
	for (int i = 0; i < charAmount; ++i) {

		if (isalpha(tabChar[i])) {
			word.push_back(tabChar[i]);
			auto it = vec.find(word);
			if (it != vec.end()) {
				s_result.push_back(it->second);
				word = "";
			}

		} else {
			s_result.push_back(tabChar[i]);
		}

	}
	delete[] tabChar;
	return s_result;
}

map<string, char> builDictionaryGG_PL(const map<char, string> &p_gg) {
	map<string, char> lex_pair;
	for (auto it = p_gg.begin(); it != p_gg.end(); ++it) {
		string key_type = it->second;
		char value_type = it->first;
		lex_pair.insert(pair<string, char>(key_type, value_type));

	}
	return lex_pair;
}
