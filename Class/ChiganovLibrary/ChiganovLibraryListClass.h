#pragma once
#include <iostream>
#include <fstream>
#include <list>
#include "ChiganovBookClass.h"

using namespace std;

class ChiganovLibraryListClass
{
	list<ChiganovBookClass*> library_;
	int amount_books_;
public:
	friend istream& operator >> (istream& in, ChiganovLibraryListClass& Library);
	friend ostream& operator << (ostream& out, ChiganovLibraryListClass& Library);

	void UnloadToFile();
	void DownloadFromFile();
	void DeleteLibrary();

	~ChiganovLibraryListClass();
};

