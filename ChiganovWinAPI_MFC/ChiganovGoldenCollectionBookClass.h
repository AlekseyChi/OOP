#pragma once
#include "ChiganovBookClass.h"
#include <string>

class ChiganovGoldenCollectionBookClass : public ChiganovBookClass
{

	int year_publish_;
	bool restored_;
public:
	DECLARE_SERIAL(ChiganovGoldenCollectionBookClass);
	virtual void Serialize(CArchive& ar) override;
	virtual void Input() override;
	virtual void Output() override;

	virtual CString getCStr() override;

	ChiganovGoldenCollectionBookClass();
	ChiganovGoldenCollectionBookClass(int Year, bool Restored, CString name, CString author, int list);
	~ChiganovGoldenCollectionBookClass();
};
