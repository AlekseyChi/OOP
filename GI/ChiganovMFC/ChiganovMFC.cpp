// ChiganovMFC.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include "framework.h"
#include "ChiganovMFC.h"
#include <iostream>
#include <list>
#include <windows.h>
#include "ChiganovLibraryListClass.h"
#include "ChiganovBookClass.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

void Menu()
{
    system("CLS");
    cout << "1. Ввести книги" << endl
        << "2. Показать книги" << endl
        << "3. Выгрузить книги" << endl
        << "4. Загрузить книги" << endl
        << "5. Удалить" << endl;
}

// Единственный объект приложения

CWinApp theApp;

using namespace std;

int main()
{
    int nRetCode = 0;

    HMODULE hModule = ::GetModuleHandle(nullptr);

    if (hModule != nullptr)
    {
        // инициализировать MFC, а также печать и сообщения об ошибках про сбое
        if (!AfxWinInit(hModule, nullptr, ::GetCommandLine(), 0))
        {
            // TODO: вставьте сюда код для приложения.
            wprintf(L"Критическая ошибка: сбой при инициализации MFC\n");
            nRetCode = 1;
        }
        else
        {
            // TODO: вставьте сюда код для приложения.
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
                    Library.Input();
                    break;
                }
                case(2):
                {
                    Library.Output();
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
    }
    else
    {
        // TODO: измените код ошибки в соответствии с потребностями
        wprintf(L"Критическая ошибка: сбой GetModuleHandle\n");
        nRetCode = 1;
    }

    return nRetCode;
}
