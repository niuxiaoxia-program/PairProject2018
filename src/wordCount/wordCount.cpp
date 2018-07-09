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
	string line;
	string word;
	regex word_regex("\\s+");
	
	vector<string> lines;
	vector<string> words;
	ifstream in("myinput.txt",ios::in);
	if (!in.good())
	{
		cout << "failed!" << endl;
	}
	while (!in.eof())
	{
		getline(in,line);
		lines.push_back(line);
		regex_token_iterator<string::iterator> i(line.begin(), line.end(), word_regex, -1);
		regex_token_iterator<string::iterator> end;
		while (i != end)
		{
			string tmp = *i;
			if (tmp.size() > 3)//
			{
			    words.push_back(tmp);
		    }
			i++;
		}
	}
	cout << "line size = " << lines.size() << endl;
	auto  v1 = lines.begin();
	while (v1 != lines.end()) {
		cout  << *v1 << endl;
		v1++;
	}
	cout << "word size = " << words.size() << endl;
	auto  v2 = words.begin();
	while (v2 != words.end()) {
		cout << *v2 << endl;
		v2++;
	}
    return 0;
}

