#include "ChiganovBookClass.h"

istream& operator >> (istream& in, ChiganovBookClass& Book)
{
	cout << "¬ведите название книги - " ;
	in >> Book.book_name_;
	cout << "¬ведите автора книги - ";
	in >> Book.book_author_;
	cout << "¬ведите количество страниц - ";
	in >> Book.book_list_;
	return in;
}

ostream& operator << (ostream& out, ChiganovBookClass& Book)
{
	out << Book.book_name_ << endl << Book.book_author_ << endl << Book.book_list_ << endl;
	return out;
}

ifstream& operator >> (ifstream& InFile, ChiganovBookClass& Book)
{
	InFile >> Book.book_name_ >> Book.book_author_ >> Book.book_list_;
	return InFile;
}

ofstream& operator << (ofstream& OutFile, ChiganovBookClass& Book)
{
	OutFile << Book.book_name_ << endl << Book.book_author_ << endl << Book.book_list_ << endl;
	return OutFile;
}

ChiganovBookClass::ChiganovBookClass(string name, string author, int list)
{
	book_name_ = name;
	book_author_ = author;
	book_list_ = list;
}

ChiganovBookClass::ChiganovBookClass()
{

}