#pragma once
#include "pch.h"

class ChiganovBookClass : public CObject
{
public:
	CString book_name_;
	CString book_author_;
	int book_list_;

	DECLARE_SERIAL(ChiganovBookClass);
	virtual void Serialize(CArchive& ar);

	//CString OnDialog();

	
	/*ChiganovBookClass(const string& name, const string& author,const int& list);
	*/ChiganovBookClass();
	virtual ~ChiganovBookClass();
};


