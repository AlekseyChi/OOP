#include "pch.h"
#include "ChiganovLibraryListClass.h"
#include "ChiganovGoldenCollectionBookClass.h"
#include <conio.h>


void ChiganovLibraryListClass::Input()
{
	cout << "Введите количество книг - ";
	int a;
	cin >> a;
	shared_ptr<ChiganovBookClass> PointerBook;
	for (int i = 1; i <= a; i++)
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

void ChiganovLibraryListClass::UnloadToFile(CArchive& ar)
{
	/*CFile f("f.dat", CFile::modeCreate | CFile::modeWrite);
	CArchive ar(&f, CArchive::store);*/

	ar << library_.size();
	for (auto book : library_)
	{
		ar << book.get();
	}
}

void ChiganovLibraryListClass::DownloadFromFile(CArchive& ar)
{
	/*CFile f("f.dat", CFile::modeRead);
	CArchive ar(&f, CArchive::load);*/

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

CSize ChiganovLibraryListClass::DrowItems(CDC* pDC)
{
	CSize size;
	size.cx = 0;
	size.cy = 5;

	for_each(library_.begin(), library_.end(), bind(&ChiganovBookClass::book_print, placeholders::_1, pDC, ref(size)));

	return size;
}