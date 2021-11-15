#pragma once
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class ChiganovBookClass: public CObject
{
protected:
	CString book_name_;
	CString book_author_;
	int book_list_;
public:
	DECLARE_SERIAL(ChiganovBookClass);
	virtual void Input();
	virtual void Output();
	virtual void Serialize(CArchive& ar);
	ChiganovBookClass(CString name, CString author, int list);
	ChiganovBookClass();
};


