#include "pch.h"
#include "ChiganovBookClass.h"

IMPLEMENT_SERIAL(ChiganovBookClass, CObject, 0);

void ChiganovBookClass::Input()
{
	string s;
	cout << endl << "Введите название книги - ";
	cin >> s;
	book_name_ = s.c_str();
	cout << "Введите автора книги - ";
	cin >> s;
	book_author_ = s.c_str();
	cout << "Введите количество страниц - ";
	cin >> book_list_;
}

void ChiganovBookClass::Output()
{
	cout << "Название книги: ";
	cout << book_name_ << endl << "Автор: " << book_author_ << endl << "Кол. страниц: " << book_list_ << endl;
}

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

ChiganovBookClass::ChiganovBookClass(CString name, CString author, int list)
	:book_name_(name), book_author_(author), book_list_(list)
{

}

ChiganovBookClass::ChiganovBookClass()
{

}