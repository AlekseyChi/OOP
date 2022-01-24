#include "pch.h"
#include "ChiganovBookClass.h"
#include "afxwin.h"
#include "ChiganovDialog.h"
#include <string>


IMPLEMENT_SERIAL(ChiganovBookClass, CObject, 0);
using namespace std;

/*void ChiganovBookClass::Input()
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
	cout << endl << "Название книги: ";
	cout << book_name_ << endl << "Автор: " << book_author_ << endl << "Кол. страниц: " << book_list_ << endl;
}
*/

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

CString ChiganovBookClass::getCStr()
{
	CString c_INFbook = book_name_ + ' ' + book_author_ + ' ' + to_string(book_list_).c_str();
	return c_INFbook;
}

void ChiganovBookClass::print_book(CDC* pDC, int* str_left, int& top, int lineHeight)
{
	pDC->TextOut(str_left[0], top, book_name_);
	pDC->TextOut(str_left[1], top, book_author_);
	pDC->TextOut(str_left[2], top, to_string(book_list_).c_str());
	top += lineHeight;
}

CString ChiganovBookClass::OnDialog()
{
	CString str = _T(" ");
	return book_name_ + str + book_author_;
}

void ChiganovBookClass::FilFields(ChiganovDialog* dlg)
{
	dlg->e_Author = book_author_;
	dlg->e_NameBook = book_name_;
	dlg->e_CountList = book_list_;
	dlg->UpdateData(false);

	dlg->SetParentVisible(true);
}

void ChiganovBookClass::Read_CEdits(ChiganovDialog* dlg)
{
	dlg->UpdateData(true);

	book_name_ = dlg->e_NameBook;
	book_author_ = dlg->e_Author;
	book_list_ = dlg->e_CountList;
}

void ChiganovBookClass::GetStrLength(int* st_Len, CDC* pDC)
{
	st_Len[0] = pDC->GetTextExtent(book_name_).cx;
	st_Len[1] = pDC->GetTextExtent(book_author_).cx;
	st_Len[2] = pDC->GetTextExtent(to_string(book_list_).c_str()).cx;
	st_Len[3] = 0;
	st_Len[4] = 0;
}
