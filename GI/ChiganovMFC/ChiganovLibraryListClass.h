#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "ChiganovBookClass.h"

using namespace std;

class ChiganovLibraryListClass
{
	vector<shared_ptr<ChiganovBookClass>> library_;
public:
	void Input();
	void Output();

	void UnloadToFile();
	void DownloadFromFile();
	void DeleteLibrary();

	~ChiganovLibraryListClass();
};

