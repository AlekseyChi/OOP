// ChiganovMFClibrary.cpp: определяет процедуры инициализации для библиотеки DLL.
//

#include "pch.h"
#include "framework.h"
#include "ChiganovMFClibrary.h"
#include "ChiganovLibraryListClass.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: если эта библиотека DLL динамически связана с библиотеками DLL MFC,
//		все функции, экспортированные из данной DLL-библиотеки, которые выполняют вызовы к
//		MFC, должны содержать макрос AFX_MANAGE_STATE в
//		самое начало функции.
//
//		Например:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// тело нормальной функции
//		}
//
//		Важно, чтобы данный макрос был представлен в каждой
//		функции до вызова MFC.  Это означает, что
//		должен стоять в качестве первого оператора в
//		функции и предшествовать даже любым объявлениям переменных объекта,
//		поскольку их конструкторы могут выполнять вызовы к MFC
//		DLL.
//
//		В Технических указаниях MFC 33 и 58 содержатся более
//		подробные сведения.
//

// CChiganovMFClibraryApp

BEGIN_MESSAGE_MAP(CChiganovMFClibraryApp, CWinApp)
END_MESSAGE_MAP()


// Создание CChiganovMFClibraryApp

CChiganovMFClibraryApp::CChiganovMFClibraryApp()
{
	// TODO: добавьте код создания,
	// Размещает весь важный код инициализации в InitInstance
}


// Единственный объект CChiganovMFClibraryApp

CChiganovMFClibraryApp theApp;


// Инициализация CChiganovMFClibraryApp

BOOL CChiganovMFClibraryApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

struct BookStruct
{
	char name[255];
	char author[255];
	int c_list;
};

struct GooldStruct
{
	char name[255];
	char author[255];
	int c_list;
	bool restor;
	int year_publish;
};

extern "C" _declspec(dllexport) int __stdcall GetLibrarySize()
{
	return LibraryList.library_.size();
}

extern "C" _declspec(dllexport) void __stdcall CreateBook()
{
	auto book = make_shared<ChiganovBookClass>();
	LibraryList.library_.push_back(book);
}

extern "C" _declspec(dllexport) void __stdcall DeleteBook(int id)
{
	LibraryList.library_.erase(LibraryList.library_.begin() + id);
}

extern "C" _declspec(dllexport) void __stdcall CreateGoldBook()
{
	auto gooldbook = make_shared<ChiganovGoldenCollectionBookClass>();
	LibraryList.library_.push_back(gooldbook);
}

extern "C" _declspec(dllexport) BOOL __stdcall IsGoldBook(int id)
{
	ChiganovGoldenCollectionBookClass* goldbook = dynamic_cast<ChiganovGoldenCollectionBookClass*>(LibraryList.library_[id].get());
	return (goldbook) ? 1 : 0;
}

extern "C" _declspec(dllexport) void __stdcall GetBook(BookStruct & book, int id)
{
	strcpy_s(book.name, LibraryList.library_[id]->book_name_);
	strcpy_s(book.author, LibraryList.library_[id]->book_author_);
	book.c_list = LibraryList.library_[id]->book_list_;
}

extern "C" _declspec(dllexport) void __stdcall GetGoldBook(GooldStruct & goldbook, int id)
{
	ChiganovGoldenCollectionBookClass* hd = dynamic_cast<ChiganovGoldenCollectionBookClass*>(LibraryList.library_[id].get());
	strcpy_s(goldbook.name, hd->book_name_);
	strcpy_s(goldbook.author, hd->book_author_);
	goldbook.c_list = hd->book_list_;
	goldbook.restor = hd->restored_;
	goldbook.year_publish = hd->year_publish_;
}

extern "C" _declspec(dllexport) void __stdcall SetBook(BookStruct & book, int id)
{
	LibraryList.library_[id]->book_name_ = book.name;
	LibraryList.library_[id]->book_author_ = book.author;
	LibraryList.library_[id]->book_list_ = book.c_list;
}

extern "C" _declspec(dllexport) void __stdcall SetGoldBook(GooldStruct & gpldbook, int id)
{
	ChiganovGoldenCollectionBookClass* hd = dynamic_cast<ChiganovGoldenCollectionBookClass*>(LibraryList.library_[id].get());
	hd->book_name_ = gpldbook.name;
	hd->book_author_ = gpldbook.author;
	hd->book_list_ = gpldbook.c_list;
	hd->restored_ = gpldbook.restor;
	hd->book_list_ = gpldbook.year_publish;
}

extern "C" _declspec(dllexport) void __stdcall SaveToFile(const char* filename)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CFile f(CString(filename), CFile::modeCreate | CFile::modeWrite);
	CArchive archive(&f, CArchive::store);
	LibraryList.SaveToFile(archive);
	archive.Close();
	f.Close();
}

extern "C" _declspec(dllexport) void __stdcall LoadFromFile(const char* filename)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CFile f(CString(filename), CFile::modeRead);
	CArchive archive(&f, CArchive::load);
	LibraryList.LoadFromFile(archive);
	archive.Close();
	f.Close();
}