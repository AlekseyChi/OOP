#pragma once

#include "ChiganovWinAPI_MFCDoc.h"
// Диалоговое окно ChiganovDialog

class CChiganovWinAPIMFCDoc;

class ChiganovDialog : public CDialogEx
{
	DECLARE_DYNAMIC(ChiganovDialog)

	CChiganovWinAPIMFCDoc* m_pDoc;

public:
	ChiganovDialog(CChiganovWinAPIMFCDoc*, CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~ChiganovDialog();
	void SetParentVisible(bool vis);
	void SetDaughterVisible(bool vis);


// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLbnSelchangeListItem();
	afx_msg void OnBnClickedButtonAdd();
	afx_msg void OnBnClickedButtonDelete();
	afx_msg void OnBnClickedButtonChange();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg BOOL OnInitDialog();
	CEdit m_NameBook;
	CEdit m_Author;
	CEdit m_CountList;
	
	CEdit m_YearPublish;
	CString e_NameBook;
	CString e_Author;
	int e_CountList;
	
	int e_YearPublish;
	afx_msg void OnBnClickedCheck1();
	CButton m_GoldCollection;
	CListBox m_ListBox;
	CEdit m_Restore;
	BOOL e_Restore;
};
