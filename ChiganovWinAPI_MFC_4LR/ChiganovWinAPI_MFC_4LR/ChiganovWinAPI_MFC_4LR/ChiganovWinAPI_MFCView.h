
// ChiganovWinAPI_MFCView.h: интерфейс класса CChiganovWinAPIMFCView
//

#pragma once


class CChiganovWinAPIMFCView : public CScrollView
{
protected: // создать только из сериализации
	CChiganovWinAPIMFCView() noexcept;
	DECLARE_DYNCREATE(CChiganovWinAPIMFCView)

// Атрибуты
public:
	CChiganovWinAPIMFCDoc* GetDocument() const;

// Операции
public:

// Переопределение
public:
	virtual void OnDraw(CDC* pDC);  // переопределено для отрисовки этого представления
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // вызывается в первый раз после конструктора

// Реализация
public:
	virtual ~CChiganovWinAPIMFCView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()
public:
	//afx_msg void OnRedoc();
};

#ifndef _DEBUG  // версия отладки в ChiganovWinAPI_MFCView.cpp
inline CChiganovWinAPIMFCDoc* CChiganovWinAPIMFCView::GetDocument() const
   { return reinterpret_cast<CChiganovWinAPIMFCDoc*>(m_pDocument); }
#endif

