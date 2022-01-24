#pragma once
#include "pch.h"
#include "ChiganovBookClass.h"

class ChiganovGoldenCollectionBookClass :
	public ChiganovBookClass
{
public:
	int year_publish_;
	bool restored_;
	DECLARE_SERIAL(ChiganovGoldenCollectionBookClass);
	void Serialize(CArchive& ar);
	
	ChiganovGoldenCollectionBookClass();
	//ChiganovGoldenCollectionBookClass(const int& count, const bool& Restored, const string& name, const string& author,const int& list);
	~ChiganovGoldenCollectionBookClass();
};
