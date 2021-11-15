#include "pch.h"
#include "ChiganovLibraryListClass.h"
#include "ChiganovGoldenCollectionBookClass.h"
#include <conio.h>

void ChiganovLibraryListClass::Input()
{
	cout << "Введите количество книг - ";
	shared_ptr<ChiganovBookClass> PointerBook;
	for (int i = 1; i <= library_.size(); i++)
	{
		cout << "Входит книга в золотую колекцию? (Да - 1, Нет - 0): ";
		if (_getche() == '0')
			PointerBook = make_shared<ChiganovBookClass>();
		else
			PointerBook = make_shared<ChiganovGoldenCollectionBookClass>();
		PointerBook->Input();
		library_.push_back(PointerBook);
	}
}

void ChiganovLibraryListClass::Output()
{
	for (auto& book : library_)
		book->Output();
}

void ChiganovLibraryListClass::UnloadToFile()
{
	CFile f("f.dat", CFile::modeCreate | CFile::modeWrite);
	CArchive ar(&f, CArchive::store);
	ar << library_.size();
	for (auto book : library_)
	{
		ar << book.get();
	}
}

void ChiganovLibraryListClass::DownloadFromFile()
{
	CFile f("f.dat", CFile::modeRead);
	CArchive ar(&f, CArchive::load);
	int iter;
	ar >> iter;
	for (int i = 0; i < iter; ++i)
	{
		ChiganovBookClass* ptr;
		ar >> ptr;
		shared_ptr<ChiganovBookClass> PointerBook(ptr);
		library_.push_back(PointerBook);
	}
}

void ChiganovLibraryListClass::DeleteLibrary()
{
	library_.clear();
}

ChiganovLibraryListClass::~ChiganovLibraryListClass()
{
	DeleteLibrary();
}

