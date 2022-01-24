#include "pch.h"
#include "ChiganovLibraryListClass.h"


void ChiganovLibraryListClass::SaveToFile(CArchive& ar)
{
	ar << library_.size();
	for (auto book : library_)
	{
		ar << book.get();
	}
}

void ChiganovLibraryListClass::LoadFromFile(CArchive& ar)
{
	int iter;
	ar >> iter;
	for (int i = 0; i < iter; ++i)
	{
		ChiganovBookClass* ptr;
		ar >> ptr;
		std::shared_ptr<ChiganovBookClass> PointerBook(ptr);
		library_.push_back(PointerBook);
	}
}

void ChiganovLibraryListClass::DeleteLibrary()
{
	library_.clear();
}

//ChiganovLibraryListClass::ChiganovLibraryListClass(const std::vector<std::shared_ptr<ChiganovBookClass>>& library)
//{
//	library_ = library;
//}

ChiganovLibraryListClass::~ChiganovLibraryListClass()
{
	DeleteLibrary();
}

//ChiganovLibraryListClass::ChiganovLibraryListClass()
//{
//	fact = 0;
//}


int ChiganovLibraryListClass::delete_book(int id)
{
	int index = id;
	if (library_.size() == id + 1)
		index = id - 1;
	library_.erase(library_.begin() + id);
	return index;
}