
// ChiganovWinAPI_MFC.h: основной файл заголовка для приложения ChiganovWinAPI_MFC
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CChiganovWinAPIMFCApp:
// Сведения о реализации этого класса: ChiganovWinAPI_MFC.cpp
//

class CChiganovWinAPIMFCApp : public CWinApp
{
public:
	CChiganovWinAPIMFCApp() noexcept;


// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CChiganovWinAPIMFCApp theApp;
