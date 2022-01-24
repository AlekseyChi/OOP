// ChiganovMFClibrary.h: основной файл заголовка для библиотеки DLL ChiganovMFClibrary
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"
#include "ChiganovLibraryListClass.h"// основные символы


// CChiganovMFClibraryApp
// Реализацию этого класса см. в файле ChiganovMFClibrary.cpp
//
ChiganovLibraryListClass LibraryList;
class CChiganovMFClibraryApp : public CWinApp
{
public:
	CChiganovMFClibraryApp();

// Переопределение
public:
	virtual BOOL InitInstance();
	DECLARE_MESSAGE_MAP()
};
