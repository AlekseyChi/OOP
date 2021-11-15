#include "pch.h"
#include "ChiganovGoldenCollectionBookClass.h"

IMPLEMENT_SERIAL(ChiganovGoldenCollectionBookClass, ChiganovBookClass, VERSIONABLE_SCHEMA | 0);

void ChiganovGoldenCollectionBookClass::Input()
{
	ChiganovBookClass::Input();
	cout << "Была риставрирована книга? (Да - 1, Нет - 0): ";
	cin >> restored_;
	cout << "Год книги: ";
	cin >> year_publish_;
}

void ChiganovGoldenCollectionBookClass::Output()
{
	ChiganovBookClass::Output();
	if (restored_)
		cout << "Книга после рестоврации" << endl;
	else
		cout << "Книга без рестоврации" << endl;
	cout << "Год издательства: " << year_publish_ << endl << endl;
}

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

CString ChiganovGoldenCollectionBookClass::getCStr()
{
	CString c_INFbook = ChiganovBookClass::getCStr();
	c_INFbook = c_INFbook + ' ' + to_string(year_publish_).c_str() + ' ' + to_string((int)restored_).c_str();
	return c_INFbook;
}

ChiganovGoldenCollectionBookClass::ChiganovGoldenCollectionBookClass() : year_publish_(0), restored_(0)
{

}

ChiganovGoldenCollectionBookClass::ChiganovGoldenCollectionBookClass(int Year, bool Restored, CString name, CString author, int list)
	: year_publish_(Year), restored_(Restored), ChiganovBookClass(name, author, list)
{

}


ChiganovGoldenCollectionBookClass::~ChiganovGoldenCollectionBookClass()
{

}