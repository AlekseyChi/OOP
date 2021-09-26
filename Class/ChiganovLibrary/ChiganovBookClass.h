#pragma once
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class ChiganovBookClass
{
	string book_name_;
	string book_author_;
	int book_list_;
public:
	friend istream& operator >> (istream& in, ChiganovBookClass& Book);
	friend ostream& operator << (ostream& out, ChiganovBookClass& Book);
	friend ifstream& operator >> (ifstream& InFile, ChiganovBookClass& Book);
	friend ofstream& operator << (ofstream& OutFile, ChiganovBookClass& Book);
	ChiganovBookClass(string name, string author, int list);
	ChiganovBookClass();
};

