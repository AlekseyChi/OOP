using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ChiganovConsolSharp
{
    [Serializable]
    public class ChiganovBookClass
    {
        private string book_name_;
        private string book_author_;
        private int book_list_;

        public virtual void InputBookByConsole()
        {
            Console.Write("Введите название книги: ");
            book_name_ = Console.ReadLine();
            Console.Write("Введите автора книга: ");
            book_author_ = Console.ReadLine();
            Console.Write("Введите количество страниц: ");
            book_list_ = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine();
        }

        public virtual void ShowBookByConsole()
        {
            Console.WriteLine();
            Console.WriteLine($@"
Название книги: {book_name_}
Автор: {book_author_}
Количество страниц: {book_list_}");
        }
    }
}
