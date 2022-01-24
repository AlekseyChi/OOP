#include "pch.h"
#include "ChiganovGoldenCollectionBookClass.h"
#include "ChiganovDialog.h"
#include <iostream>

using namespace std;

IMPLEMENT_SERIAL(ChiganovGoldenCollectionBookClass, ChiganovBookClass, VERSIONABLE_SCHEMA | 0);

/*void ChiganovGoldenCollectionBookClass::Input()
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
*/

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

void ChiganovGoldenCollectionBookClass::FilFields(ChiganovDialog* dlg)
{
	ChiganovBookClass::FilFields(dlg);
	dlg->e_YearPublish = year_publish_;
	string str;
	if (restored_)
	{
		//str = "Да";
		dlg->e_Restore = 1;
	}
	else 
	{
		//str = "Нет";
		dlg->e_Restore = 0;
	}

	dlg->UpdateData(false);

	dlg->m_GoldCollection.SetCheck(true);
	dlg->SetDaughterVisible(true);
}

void ChiganovGoldenCollectionBookClass::Read_CEdits(ChiganovDialog* dlg)
{
	ChiganovBookClass::Read_CEdits(dlg);
	year_publish_ = dlg->e_YearPublish;
	restored_ = dlg->e_Restore;
}

void ChiganovGoldenCollectionBookClass::GetStrLength(int* st_Len, CDC* pDC)
{
	ChiganovBookClass::GetStrLength(st_Len, pDC);
	st_Len[3] = pDC->GetTextExtent(to_string(year_publish_).c_str()).cx;
	st_Len[4] = pDC->GetTextExtent(to_string(restored_).c_str()).cx;
}

void ChiganovGoldenCollectionBookClass::print_book(CDC* pDC, int* str_left, int& top, int lineHeight)
{
	pDC->TextOut(str_left[3], top, to_string(year_publish_).c_str());
	pDC->TextOut(str_left[4], top, to_string(restored_).c_str());
	ChiganovBookClass::print_book(pDC, str_left, top, lineHeight);
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