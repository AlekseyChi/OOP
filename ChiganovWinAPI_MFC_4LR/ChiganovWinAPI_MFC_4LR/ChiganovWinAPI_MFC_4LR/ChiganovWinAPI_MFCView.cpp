
// ChiganovWinAPI_MFCView.cpp: реализация класса CChiganovWinAPIMFCView
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "ChiganovWinAPI_MFC.h"
#endif

#include "ChiganovWinAPI_MFCDoc.h"
#include "ChiganovWinAPI_MFCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChiganovWinAPIMFCView

IMPLEMENT_DYNCREATE(CChiganovWinAPIMFCView, CScrollView)

BEGIN_MESSAGE_MAP(CChiganovWinAPIMFCView, CScrollView)
	//ON_COMMAND(ID_REDOC, &CChiganovWinAPIMFCView::OnRedoc)
END_MESSAGE_MAP()

// Создание или уничтожение CChiganovWinAPIMFCView

CChiganovWinAPIMFCView::CChiganovWinAPIMFCView() noexcept
{
	// TODO: добавьте код создания

}

CChiganovWinAPIMFCView::~CChiganovWinAPIMFCView()
{
}

BOOL CChiganovWinAPIMFCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

// Рисование CChiganovWinAPIMFCView

void CChiganovWinAPIMFCView::OnDraw(CDC* pDC)
{
	CChiganovWinAPIMFCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: добавьте здесь код отрисовки для собственных данных
	CSize sizeTotal = pDoc->Library.draw_in_window(pDC);
	SetScrollSizes(MM_TEXT, sizeTotal);

}

void CChiganovWinAPIMFCView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: рассчитайте полный размер этого представления
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// Диагностика CChiganovWinAPIMFCView

#ifdef _DEBUG
void CChiganovWinAPIMFCView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CChiganovWinAPIMFCView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CChiganovWinAPIMFCDoc* CChiganovWinAPIMFCView::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CChiganovWinAPIMFCDoc)));
	return (CChiganovWinAPIMFCDoc*)m_pDocument;
}
#endif //_DEBUG


// Обработчики сообщений CChiganovWinAPIMFCView


