#include "pch.h"
#include "ChiganovBookClass.h"
IMPLEMENT_SERIAL(ChiganovBookClass, CObject, 0)

void ChiganovBookClass::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << book_name_ << book_author_ << book_list_;
	}
	else
	{
		ar >> book_name_ >> book_author_ >> book_list_;
	}
}

//CString ChiganovBookClass::OnDialog()
//{
//	CString str = _T(" ");
//	return book_name_ + str + book_author_;
//}

//ChiganovBookClass::ChiganovBookClass(const string& name,const string& author,const int& list)
//{
//	book_name_ = CString(name.c_str());
//	book_author_ = CString(author.c_str());
//	book_list_ = list;
//}

ChiganovBookClass::ChiganovBookClass()
{
	book_name_ = "Книга";
	book_author_ = "Автор";
	book_list_ = 0;
}

ChiganovBookClass::~ChiganovBookClass()
{
}
