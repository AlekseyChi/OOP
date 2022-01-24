#pragma once
#include "ChiganovBookClass.h"
#include "ChiganovGoldenCollectionBookClass.h"

class ChiganovDialog;

class ChiganovLibraryListClass
{
	std::vector<std::shared_ptr<ChiganovBookClass>> library_;
public:
	//void Input();
	//void Output();

	void UnloadToFile(CArchive& ar);
	void DownloadFromFile(CArchive& ar);
	void DeleteLibrary();
	void OutOnListBox(ChiganovDialog* dlg, int activeItem);
	void OpenObject(ChiganovDialog* dlg, int id);
	int delete_book(int id);
	void SaveObject(ChiganovDialog* dlg, bool child, int id = -1);

	/*CString getCStr();
	void book_print(CDC* pDC, CSize& XY);*/
	CSize draw_in_window(CDC* pDC);

	~ChiganovLibraryListClass();
};

