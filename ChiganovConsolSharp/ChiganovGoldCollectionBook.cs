using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ChiganovConsolSharp
{
    [Serializable]
    public class ChiganovGoldCollectionBook:ChiganovBookClass
    {
        private bool book_restor_;
        private int book_year_publish;

        public override void InputBookByConsole()
        {
            base.InputBookByConsole();
            Console.Write("Была ли книга восстановлена?(Да/Нет): ");
            if (Console.ReadLine() == "Да")
                book_restor_ = true;
            else book_restor_ = false;
            Console.Write("Год публикации книги: ");
            book_year_publish = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine();
        }

        public override void ShowBookByConsole()
        {
            base.ShowBookByConsole();
            Console.WriteLine($"Год публикации: {book_year_publish}");
            if (book_restor_)
                Console.WriteLine("Книга восстановленная");
            else Console.WriteLine("Книга невосстановленная");
        }
    }
}
