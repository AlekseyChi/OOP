#include "ChiganovLibraryListClass.h"

istream& operator >> (istream& in, ChiganovLibraryListClass& Library)
{
	cout << "¬ведите количество книг - ";
	in >> Library.amount_books_;
	for (int i = 1; i <= Library.amount_books_; i++)
	{
		ChiganovBookClass* PointerBook = new ChiganovBookClass;
		in >> *PointerBook;
		Library.library_.push_back(PointerBook);
	}
	return in;
}

ostream& operator << (ostream& out, ChiganovLibraryListClass& Library)
{
	for (auto book : Library.library_)
		out << *book << endl;
	return out;
}

void ChiganovLibraryListClass::UnloadToFile()
{
	string Name;
	cout << "¬ведите название файла - ";
	cin >> Name;
	ofstream File(Name + ".txt", ios::out);
	if (File.is_open())
	{
		File << amount_books_;
		for (auto book : library_)
			File << *book << endl;
	}
	else
	{
		cout << "‘айл не открылс€";
		system("pause");
	}
}

void ChiganovLibraryListClass::DownloadFromFile()
{
	string Name;
	cout << "¬ведите название файла - ";
	cin >> Name;
	ifstream File(Name + ".txt", ios::in);
	if (File.is_open())
	{
		File >> amount_books_;
		for (int i = 1; i <= amount_books_; i++)
		{
			ChiganovBookClass* PointerBook = new ChiganovBookClass;
			File >> *PointerBook;
			library_.push_back(PointerBook);
		}
	}
	else
	{
		cout << "‘айл не открылс€";
		system("pause");
	}
}

void ChiganovLibraryListClass::DeleteLibrary()
{
	delete& amount_books_;
	for (auto iter = library_.begin(); iter != library_.end(); iter++)
	{
		delete* iter;
	}
	library_.clear();
}

ChiganovLibraryListClass::~ChiganovLibraryListClass()
{
	DeleteLibrary();
}