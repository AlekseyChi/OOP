// ChiganovDialog.cpp: файл реализации
//

#include "pch.h"
#include "ChiganovWinAPI_MFC.h"
#include "ChiganovDialog.h"
#include "afxdialogex.h"


// Диалоговое окно ChiganovDialog

IMPLEMENT_DYNAMIC(ChiganovDialog, CDialogEx)

ChiganovDialog::ChiganovDialog(CChiganovWinAPIMFCDoc* pDocIni, CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, e_NameBook(_T(""))
	, e_Author(_T(""))
	, e_CountList(0)
	, e_YearPublish(0)
	, e_Restore(false)
{
	this->m_pDoc = pDocIni;
}

ChiganovDialog::~ChiganovDialog()
{
}

void ChiganovDialog::SetParentVisible(bool vis)
{
	int visible = (vis) ? SW_SHOW : SW_HIDE;
	m_NameBook.ShowWindow(visible);
	m_Author.ShowWindow(visible);
	m_CountList.ShowWindow(visible);
}

void ChiganovDialog::SetDaughterVisible(bool vis)
{
	int visible = (vis) ? SW_SHOW : SW_HIDE;
	m_Restore.ShowWindow(visible);
	m_YearPublish.ShowWindow(visible);
}

void ChiganovDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_NAME_BOOK, m_NameBook);
	DDX_Control(pDX, IDC_EDIT_AUTHOR, m_Author);
	DDX_Control(pDX, IDC_EDIT_COUNT_LIST, m_CountList);
	DDX_Control(pDX, IDC_EDIT_YEAR_PUBLISH, m_YearPublish);
	DDX_Text(pDX, IDC_EDIT_NAME_BOOK, e_NameBook);
	DDX_Text(pDX, IDC_EDIT_AUTHOR, e_Author);
	DDX_Text(pDX, IDC_EDIT_COUNT_LIST, e_CountList);
	DDX_Text(pDX, IDC_EDIT_YEAR_PUBLISH, e_YearPublish);
	DDX_Control(pDX, IDC_CHECK1, m_GoldCollection);
	DDX_Control(pDX, IDC_LIST_ITEM, m_ListBox);
	DDX_Control(pDX, IDC_EDIT_RESTORE, m_Restore);
	DDX_Text(pDX, IDC_EDIT_RESTORE, e_Restore);
}


BEGIN_MESSAGE_MAP(ChiganovDialog, CDialogEx)
	ON_LBN_SELCHANGE(IDC_LIST_ITEM, &ChiganovDialog::OnLbnSelchangeListItem)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &ChiganovDialog::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &ChiganovDialog::OnBnClickedButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_CHANGE, &ChiganovDialog::OnBnClickedButtonChange)
	ON_BN_CLICKED(IDOK, &ChiganovDialog::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &ChiganovDialog::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_CHECK1, &ChiganovDialog::OnBnClickedCheck1)
END_MESSAGE_MAP()


// Обработчики сообщений ChiganovDialog
BOOL ChiganovDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SetParentVisible(true);
	SetDaughterVisible(IsDlgButtonChecked(IDC_CHECK1));
	m_pDoc->Library.OutOnListBox(this, -1);

	return TRUE;
}

void ChiganovDialog::OnLbnSelchangeListItem()
{
	// TODO: добавьте свой код обработчика уведомлений
	m_pDoc->Library.OutOnListBox(this, m_ListBox.GetCurSel());
}


void ChiganovDialog::OnBnClickedButtonAdd()
{
	// TODO: добавьте свой код обработчика уведомлений
	m_pDoc->Library.SaveObject(this, IsDlgButtonChecked(IDC_CHECK1));

	m_pDoc->Library.OutOnListBox(this, -3);
}


void ChiganovDialog::OnBnClickedButtonDelete()
{
	// TODO: добавьте свой код обработчика уведомлений
	int curSel = m_ListBox.GetCurSel();
	if (curSel < 0) return;

	curSel = (m_pDoc->Library.delete_book(curSel));
	m_pDoc->Library.OutOnListBox(this, curSel);
}


void ChiganovDialog::OnBnClickedButtonChange()
{
	// TODO: добавьте свой код обработчика уведомлений
	int a = m_ListBox.GetCurSel();
	if (a < 0)
		m_pDoc->Library.SaveObject(this, IsDlgButtonChecked(IDC_CHECK1));
	else
		m_pDoc->Library.SaveObject(this, IsDlgButtonChecked(IDC_CHECK1), a);
	m_pDoc->Library.OutOnListBox(this, a);
}


void ChiganovDialog::OnBnClickedOk()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (AfxMessageBox("Уверены, что хотите выйти?", MB_YESNO) == IDYES)
	{
		CDialogEx::OnCancel();
	}
}


void ChiganovDialog::OnBnClickedCancel()
{
	// TODO: добавьте свой код обработчика уведомлений
	CDialogEx::OnOK();
}


void ChiganovDialog::OnBnClickedCheck1()
{
	// TODO: добавьте свой код обработчика уведомлений
	SetDaughterVisible(IsDlgButtonChecked(IDC_CHECK1));
}