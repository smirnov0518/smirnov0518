#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<list>

	using std::list;
	using std::string;
	using std::cout;
	using std::cin;
	using std::endl;
	using std::fstream;
	struct part {
		string surname;
		string name;
		string age;
		string work;
		string id;
	};
	
	
	void redact();
	int init();
	void adding(int mode, int ind);
	void exit_init(bool mode);
	void deleting();
	void temping(bool mode,int ind);
	void searching();
