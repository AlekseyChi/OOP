#pragma once
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include "ChiganovBookClass.h"

class cDlgView;
class cDlgEdit;

using namespace std;

class ChiganovLibraryListClass
{
	vector<shared_ptr<ChiganovBookClass>> library_;
public:
	void Input();
	void Output();

	void UnloadToFile(CArchive& ar);
	void DownloadFromFile(CArchive& ar);
	void DeleteLibrary();

	CString getCStr();
	void book_print(CDC* pDC, CSize& XY);
	CSize DrowItems(CDC* pDC);

	~ChiganovLibraryListClass();
};

