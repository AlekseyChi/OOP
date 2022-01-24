
// ChiganovWinAPI_MFCDoc.cpp: реализация класса CChiganovWinAPIMFCDoc 
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "ChiganovWinAPI_MFC.h"
#endif

#include "ChiganovWinAPI_MFCDoc.h"
#include "ChiganovDialog.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CChiganovWinAPIMFCDoc

IMPLEMENT_DYNCREATE(CChiganovWinAPIMFCDoc, CDocument)

BEGIN_MESSAGE_MAP(CChiganovWinAPIMFCDoc, CDocument)
	ON_COMMAND(ID_REDOC, &CChiganovWinAPIMFCDoc::OnRedoc)
END_MESSAGE_MAP()


// Создание или уничтожение CChiganovWinAPIMFCDoc

CChiganovWinAPIMFCDoc::CChiganovWinAPIMFCDoc() noexcept
{
	// TODO: добавьте код для одноразового вызова конструктора

}

CChiganovWinAPIMFCDoc::~CChiganovWinAPIMFCDoc()
{
}

BOOL CChiganovWinAPIMFCDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: добавьте код повторной инициализации
	// (Документы SDI будут повторно использовать этот документ)

	Library.DeleteLibrary();

	return TRUE;
}




// Сериализация CChiganovWinAPIMFCDoc

void CChiganovWinAPIMFCDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: добавьте код сохранения
		Library.UnloadToFile(ar);
	}
	else
	{
		// TODO: добавьте код загрузки
		Library.DownloadFromFile(ar);
	}
}

#ifdef SHARED_HANDLERS

// Поддержка для эскизов
void CChiganovWinAPIMFCDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Измените этот код для отображения данных документа
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Поддержка обработчиков поиска
void CChiganovWinAPIMFCDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Задание содержимого поиска из данных документа.
	// Части содержимого должны разделяться точкой с запятой ";"

	// Например:  strSearchContent = _T("точка;прямоугольник;круг;объект ole;");
	SetSearchContent(strSearchContent);
}

void CChiganovWinAPIMFCDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// Диагностика CChiganovWinAPIMFCDoc

#ifdef _DEBUG
void CChiganovWinAPIMFCDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CChiganovWinAPIMFCDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Команды CChiganovWinAPIMFCDoc
/*void CChiganovWinAPIMFCDoc::OnRedoc()
{
	ChiganovDialog dlg_base(this);
	if (dlg_base.DoModal() == IDCANCEL)
	{
		UpdateAllViews(NULL);
	}
}
*/

void CChiganovWinAPIMFCDoc::OnRedoc()
{
	// TODO: добавьте свой код обработчика команд
	ChiganovDialog dlg_base(this);
	if (dlg_base.DoModal() == IDCANCEL)
	{
		UpdateAllViews(NULL);
	}
}
