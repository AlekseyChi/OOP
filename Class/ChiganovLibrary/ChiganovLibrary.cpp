﻿// ChiganovLibrary.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <list>
#include <windows.h>
#include "ChiganovLibraryListClass.h"
#include "ChiganovBookClass.h"

using namespace std;

void Menu()
{
    system("CLS");
    cout << "1. Ввести книги" << endl
        << "2. Показать книги" << endl
        << "3. Выгрузить книги" << endl
        << "4. Загрузить книги" << endl
        << "5. Удалить" << endl;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int a;
    ChiganovLibraryListClass Library;
    while (1)
    {
        Menu();
        cout << "Выберите пункт - ";
        cin >> a;
        switch (a)
        {
            case(1):
            {
                cin >> Library;
                break;
            }
            case(2):
            {
                cout << Library;
                system("pause");
                break;
            }
            case(3):
            {
                Library.UnloadToFile();
                break;
            }
            case(4):
            {
                Library.DownloadFromFile();
                break;
            }
            case(5):
            {
                Library.DeleteLibrary();
                break;
            }
            default:
                break;
        }
    }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.