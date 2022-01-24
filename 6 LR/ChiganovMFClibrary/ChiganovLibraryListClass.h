#pragma once
#include "pch.h"
#include "ChiganovBookClass.h"
#include "ChiganovGoldenCollectionBookClass.h"

class ChiganovLibraryListClass
{
public:
	std::vector<std::shared_ptr<ChiganovBookClass>> library_;

	void SaveToFile(CArchive& ar);
	void LoadFromFile(CArchive& ar);
	void DeleteLibrary();
	int delete_book(int id);

	//ChiganovLibraryListClass(const std::vector<std::shared_ptr<ChiganovBookClass>>& library);
	~ChiganovLibraryListClass();
	//ChiganovLibraryListClass();

};

