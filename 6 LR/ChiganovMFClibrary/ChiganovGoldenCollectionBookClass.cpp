#include "pch.h"
#include "ChiganovGoldenCollectionBookClass.h"
IMPLEMENT_SERIAL(ChiganovGoldenCollectionBookClass, ChiganovBookClass, VERSIONABLE_SCHEMA | 0)

void ChiganovGoldenCollectionBookClass::Serialize(CArchive& ar)
{
	ChiganovBookClass::Serialize(ar);

	if (ar.IsStoring())
	{
		ar << year_publish_ << restored_;
	}
	else
	{
		ar >> year_publish_ >> restored_;
	}
}

ChiganovGoldenCollectionBookClass::ChiganovGoldenCollectionBookClass()
{
	book_name_ = _T("Книга");
	book_author_ = _T("Автор");
	book_list_ = 0;
	restored_ = false;
	year_publish_ = 0;
}

//ChiganovGoldenCollectionBookClass::ChiganovGoldenCollectionBookClass(const int& count, const bool& Restored, const string& name, const string& author, const int& list)
//{
//	book_name_ = CString(name.c_str());
//	book_author_ = CString(author.c_str());
//	book_list_ = list;
//	restored_ = Restored;
//	year_publish_ = count;
//}


ChiganovGoldenCollectionBookClass::~ChiganovGoldenCollectionBookClass()
{

}