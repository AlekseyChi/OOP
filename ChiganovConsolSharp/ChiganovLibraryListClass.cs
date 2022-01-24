using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.Serialization.Formatters.Binary;
using System.IO;


namespace ChiganovConsolSharp
{
    [Serializable]
    public class ChiganovLibraryListClass
    {
        private List<ChiganovBookClass> library_ = new List<ChiganovBookClass>();

        public void InputBookByConsole()
        {
            Console.WriteLine();
            Console.Write("1 - Добавить книгу из золотой коллекции\n0 - Добавить обычную книгу: ");
            bool book_selection;
            if (Console.ReadLine() == "0")
                book_selection = false;
            else book_selection = true;
            ChiganovBookClass m_book;
            if (book_selection == false)
            {
                m_book = new ChiganovBookClass();
            }
            else
            {
                m_book = new ChiganovGoldCollectionBook();
            }
            m_book.InputBookByConsole();
            library_.Add(m_book);
        }

        public void ShowBookByConsole()
        {
            if (library_.Count() != 0)
            {
                foreach (dynamic book in library_)
                {
                    book.ShowBookByConsole();
                    Console.WriteLine();
                }
            }
            else Console.WriteLine("Данные пусты!");
        }

        public void DeleteLibrary()
        {
            if (library_.Count() != 0)
                library_.Clear();
            else Console.WriteLine("Данные пусты!");
        }

        public void DownloadFromFile()
        {
            Console.Write("\nВведите имя файла: ");
            string file_name = Console.ReadLine();
            using (FileStream f_load = new FileStream(file_name + ".txt", FileMode.Open))
            {
                BinaryFormatter load = new BinaryFormatter();
                library_ = load.Deserialize(f_load) as List<ChiganovBookClass>;
            }
        }

        public void UnloadToFile()
        {
            Console.Write("\nВведите имя файла: ");
            string file_name = Console.ReadLine();
            using (FileStream f_save = new FileStream(file_name + ".txt", FileMode.OpenOrCreate))
            {
                BinaryFormatter save = new BinaryFormatter();
                save.Serialize(f_save, library_);
            }
        }

        public ChiganovLibraryListClass()
        {

        }

        ~ChiganovLibraryListClass()
        {
            library_.Clear();
        }
    }
}
