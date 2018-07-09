// wordCount.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <regex>
#include <algorithm>


using namespace std;

int main()
{
	size_t size_characters=0;
	size_t size_words=0;
	size_t size_lines=0;

	string line;
	string word;
	
	regex word_regex("[A-Za-z][A-Za-z][A-Za-z][A-Za-z][[:w:]]+");
	
	vector<string> lines;
	vector<string> words;
	ifstream in("myinput.txt",ios::in);
	//ifstream in("bible-kjv.txt", ios::in);
	if (!in.good())
	{
		cout << "failed to open file!" << endl;
	}
	while (!in.eof())
	{
		getline(in,line);
		if(line.size()!=0)
		{
			lines.push_back(line);
			size_characters = size_characters + line.size();
		
			sregex_token_iterator pos(line.cbegin(), line.cend(), word_regex);
			sregex_token_iterator end;
		
			while (pos != end) {
				//cout << pos->str() << endl;
				words.push_back(pos->str());
				pos++;
			}
		}
	}

	size_lines = lines.size();
	size_words = words.size();
	
	/*
	auto  v1 = lines.begin();
	while (v1 != lines.end()) {
		cout  << *v1 << endl;
		v1++;
	}
	
	auto  v2 = words.begin();
	while (v2 != words.end()) {
		cout << *v2 << endl;
		v2++;
	}
	*/
	
	cout << "characters:" << size_characters << endl;
	cout << "words:" << size_words << endl;
	cout << "lines:" << size_lines << endl;
	
    return 0;
}

