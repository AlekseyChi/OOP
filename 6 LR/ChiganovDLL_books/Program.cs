using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Runtime.InteropServices;
using System.Windows.Forms;

namespace ChiganovDLL_books
{
    [StructLayout(LayoutKind.Sequential, CharSet = CharSet.Ansi)]
    struct Book
    {
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 255)]
        public string name;
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 255)]
        public string author;
        [MarshalAs(UnmanagedType.I4)]
        public int c_list;
    };

    [StructLayout(LayoutKind.Sequential, CharSet = CharSet.Ansi)]
    struct GoldBook
    {
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 255)]
        public string name;
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 255)]
        public string author;
        [MarshalAs(UnmanagedType.I4)]
        public int c_list;
        [MarshalAs(UnmanagedType.Bool)]
        public bool restor;
        [MarshalAs(UnmanagedType.I4)]
        public int year_publish;
    };

    static class Program
    {
        /// <summary>
        /// Главная точка входа для приложения.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Form1());
        }
    }
}
