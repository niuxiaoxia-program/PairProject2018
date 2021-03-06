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

struct word_freq
{
	string word;
	long freq;
	bool operator < (word_freq & b) {
		return freq > b.freq;
	}
	bool operator <=(word_freq & b) {
		return freq >= b.freq;
	}

};

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
	
	
	
	cout << "characters:" << size_characters << endl;
	cout << "words:" << size_words << endl;
	cout << "lines:" << size_lines << endl;
	
	list<word_freq> word_list;

	auto  vw = words.begin();
	while (vw != words.end()) {
		word_freq tmp;
		tmp.word = *vw;
		tmp.freq = 1;
		bool word_found = false;
		auto  vwf = word_list.begin();
		while (vwf != word_list.end()) {
			if(tmp.word == vwf->word)
			{
				word_found = true;
				vwf->freq++;
				break;
			}
			vwf++;
		}
		if (!word_found)
		{
			word_list.push_back(tmp);
		}
		vw++;
	}
	cout << "----------------------" << endl;
	word_list.sort();
	unsigned int num=0;
	auto  vwf = word_list.begin();
	while (vwf != word_list.end()) {
		
		cout << vwf->word << ":" << vwf->freq << endl;
		vwf++;
		num++;
		if (num >= 10) break;
	}

    return 0;
}

