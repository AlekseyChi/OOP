#pragma once
#include <afx.h>
#include <string>
#include <iostream>


class ChiganovDialog;

class ChiganovBookClass : public CObject
{
public:
	CString book_name_;
	CString book_author_;
	int book_list_;
public:
	DECLARE_SERIAL(ChiganovBookClass);
	//virtual void Input();
	//virtual void Output();
	virtual void Serialize(CArchive& ar);

	virtual CString getCStr();
	virtual void print_book(CDC* pDC, int* str_left, int& top, int lineHeight);
	CString OnDialog();

	virtual void FilFields(ChiganovDialog* dlg);
	virtual void Read_CEdits(ChiganovDialog* dlg);
	virtual void GetStrLength(int* st_Len, CDC* pDC);

	ChiganovBookClass(CString name, CString author, int list);
	ChiganovBookClass();
};


