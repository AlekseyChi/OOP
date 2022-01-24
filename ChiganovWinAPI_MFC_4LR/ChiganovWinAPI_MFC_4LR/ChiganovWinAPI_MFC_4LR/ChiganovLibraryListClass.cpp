#include "pch.h"
#include "ChiganovLibraryListClass.h"
#include "ChiganovGoldenCollectionBookClass.h"
#include <conio.h>
#include "ChiganovDialog.h"
#include <iostream>

using namespace std;

/*void ChiganovLibraryListClass::Input()
{
	cout << "������� ���������� ���� - ";
	int a;
	cin >> a;
	shared_ptr<ChiganovBookClass> PointerBook;
	for (int i = 1; i <= a; i++)
	{
		cout << "������ ����� � ������� ��������? (�� - 1, ��� - 0): ";
		if (_getche() == '0')
			PointerBook = make_shared<ChiganovBookClass>();
		else
			PointerBook = make_shared<ChiganovGoldenCollectionBookClass>();
		PointerBook->Input();
		library_.push_back(PointerBook);
	}
}

void ChiganovLibraryListClass::Output()
{
	for (auto& book : library_)
		book->Output();
}
*/
void ChiganovLibraryListClass::UnloadToFile(CArchive& ar)
{
	/*CFile f("f.dat", CFile::modeCreate | CFile::modeWrite);
	CArchive ar(&f, CArchive::store);*/

	ar << library_.size();
	for (auto book : library_)
	{
		ar << book.get();
	}
}

void ChiganovLibraryListClass::DownloadFromFile(CArchive& ar)
{
	/*CFile f("f.dat", CFile::modeRead);
	CArchive ar(&f, CArchive::load);*/

	int iter;
	ar >> iter;
	for (int i = 0; i < iter; ++i)
	{
		ChiganovBookClass* ptr;
		ar >> ptr;
		shared_ptr<ChiganovBookClass> PointerBook(ptr);
		library_.push_back(PointerBook);
	}
}

void ChiganovLibraryListClass::DeleteLibrary()
{
	library_.clear();
}

CSize ChiganovLibraryListClass::draw_in_window(CDC* pDC)
{
	CString head[5] = { "�������� �����", "�����", "���������� ���.", "��� ����������", "�������." };

	int str_len[5];
	for (int i = 0; i < 5; i++)
		str_len[i] = pDC->GetTextExtent(head[i]).cx;

	for (auto item : library_)
	{
		int memLen[5];
		item->GetStrLength(memLen, pDC);
		for (int i = 0; i < 5; i++)
		{
			if (memLen[i] > str_len[i])
				str_len[i] = memLen[i];
		}
	}
	str_len[0] += 5;
	for (int i = 1; i < 5; i++)
	{
		str_len[i - 1] += 15;
		str_len[i] += str_len[i - 1];
	}
	int str_left[5];
	str_left[0] = 5;
	for (int i = 1; i < 5; i++)
		str_left[i] = str_len[i - 1];

	int top = 5;
	for (int i = 0; i < 5; i++)
	{
		pDC->TextOutA(str_left[i], top, head[i]);
	}
	top += 30;

	for_each(library_.begin(), library_.end(), bind(&ChiganovBookClass::print_book, placeholders::_1, pDC, str_left, ref(top), 30));
	CSize XY;
	XY.cx = str_len[4] + 5;
	XY.cy = top;
	// ������ ������� �������
	POINT sizeAll;
	sizeAll.x = str_len[4] + 5;
	sizeAll.y = 30;

	// �������������� �����
	pDC->MoveTo(0, 0);
	pDC->LineTo(sizeAll.x, 0);
	pDC->LineTo(sizeAll);
	pDC->LineTo(0, sizeAll.y);
	pDC->LineTo(0, 0);
	return XY;
}

ChiganovLibraryListClass::~ChiganovLibraryListClass()
{
	DeleteLibrary();
}

void ChiganovLibraryListClass::OutOnListBox(ChiganovDialog* dlg, int activeItem)
{
	// ������ list box
	dlg->m_ListBox.ResetContent();

	// ���� ������ ������ - �����
	if (library_.empty()) return;

	// ������� ������ ��������
	for_each(library_.begin(), library_.end(), [&](shared_ptr<ChiganovBookClass> obj)
		{
			dlg->m_ListBox.AddString(obj->OnDialog());
		});

	// ���������� ���������  �������
	int qt = library_.size();

	// ���� ���� ������� ��������� �����, ������� ���
	if (activeItem == -3)
		activeItem = qt - 1;

	// ������� ������ � ������� ��� ����������
	if (activeItem > -1)
	{
		library_[activeItem]->FilFields(dlg);
		dlg->m_ListBox.SetCurSel(activeItem);
	}

}

void ChiganovLibraryListClass::OpenObject(ChiganovDialog* dlg, int id)
{
	auto sel_object = library_[id];
	sel_object->FilFields(dlg);
}

int ChiganovLibraryListClass::delete_book(int id)
{
	int index = id;
	if (library_.size() == id + 1)
		index = id - 1;
	library_.erase(library_.begin() + id);
	return index;
}

void ChiganovLibraryListClass::SaveObject(ChiganovDialog* dlg, bool child, int id)
{
	shared_ptr<ChiganovBookClass> object;
	if (child)
		object = make_shared<ChiganovGoldenCollectionBookClass>();
	else
		object = make_shared<ChiganovBookClass>();
	object->Read_CEdits(dlg);
	if (id < 0)
		library_.push_back(object);
	else
		library_[id] = object;
}
