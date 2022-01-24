#pragma once
#include "ChiganovBookClass.h"


class ChiganovDialog;

class ChiganovGoldenCollectionBookClass :
	public ChiganovBookClass
{
	int year_publish_;
	bool restored_;
public:
	DECLARE_SERIAL(ChiganovGoldenCollectionBookClass);
	void Serialize(CArchive& ar) override;
	//void Input() override;
	//void Output() override;

	CString getCStr() override;
	void FilFields(ChiganovDialog* dlg) override;
	void Read_CEdits(ChiganovDialog* dlg) override;
	void GetStrLength(int* st_Len, CDC* pDC)override;
	void print_book(CDC* pDC, int* str_left, int& top, int lineHeight) override;

	ChiganovGoldenCollectionBookClass();
	ChiganovGoldenCollectionBookClass(int Year, bool Restored, CString name, CString author, int list);
	~ChiganovGoldenCollectionBookClass();
};
