using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ChiganovConsolSharp
{
    class Program
    {
        public static void menu()
        {
			Console.Clear();
            Console.WriteLine("1. Ввести книгу");
            Console.WriteLine("2. Показать книги");
            Console.WriteLine("3. Выгрузить книги");
            Console.WriteLine("4. Загрузить книги");
            Console.WriteLine("5. Удалить");
        }
        static void Main(string[] args)
        {
            ChiganovLibraryListClass Library = new ChiganovLibraryListClass();

            while(true)
            {
                menu();
                int a;
				Console.Write("Введите команду: ");
				a = Convert.ToInt32(Console.ReadLine());
				switch (a)
				{
					case 1:
						{
							Library.InputBookByConsole();
							break;
						}
					case 2:
						{
							Library.ShowBookByConsole();
							Console.ReadLine();
							break;
						}
					case 3:
						{
							Library.UnloadToFile(); 

							break;
						}
					case 4:
						{
							Library.DownloadFromFile();

							break;
						}
					case 5:
						{
							Library.DeleteLibrary();

							break;
						}
				}
			}
        }
    }
}
