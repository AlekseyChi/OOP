using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Runtime.InteropServices;
using System.IO;

namespace ChiganovDLL_books
{
    public partial class Form2 : Form
    {
        #region Header
        public ListBox listBox;
        public bool isEditing;
        public bool isgoldbook = false;
        public Action OnCloseDialog;

        [DllImport("ChiganovMFClibrary.dll", CharSet = CharSet.Ansi)]
        private static extern int GetLibrarySize();
        [DllImport("ChiganovMFClibrary.dll", CharSet = CharSet.Ansi)]
        private static extern void CreateBook();
        [DllImport("ChiganovMFClibrary.dll", CharSet = CharSet.Ansi)]
        private static extern void GetBook(ref Book book, int id);
        [DllImport("ChiganovMFClibrary.dll", CharSet = CharSet.Ansi)]
        private static extern void SetBook(ref Book book, int id);
        [DllImport("ChiganovMFClibrary.dll", CharSet = CharSet.Ansi)]
        private static extern void CreateGoldBook();
        [DllImport("ChiganovMFClibrary.dll", CharSet = CharSet.Ansi)]
        private static extern void GetGoldBook(ref GoldBook goldbook, int id);
        [DllImport("ChiganovMFClibrary.dll", CharSet = CharSet.Ansi)]
        private static extern void SetGoldBook(ref GoldBook goldbook, int id);
        [DllImport("ChiganovMFClibrary.dll", CharSet = CharSet.Ansi)]
        private static extern bool IsGoldBook(int id);
        [DllImport("ChiganovMFClibrary.dll", CharSet = CharSet.Ansi)]
        private static extern void DeleteBook(int id);
        [DllImport("ChiganovMFClibrary.dll", CharSet = CharSet.Ansi)]
        private static extern void SaveToFile(StringBuilder filename);
        [DllImport("ChiganovMFClibrary.dll", CharSet = CharSet.Ansi)]
        private static extern void LoadFromFile(StringBuilder filename);
        #endregion

        public Form2()
        {
            InitializeComponent();
        }

        public Form2(ref ListBox listBox1, Action updateInfoMethod, bool isEditing = false)
        {
            this.isEditing = isEditing;
            listBox = listBox1;
            OnCloseDialog = updateInfoMethod;
            InitializeComponent();
            if (!isEditing)
            {
                NameBook.Text = "Книга";
                Author.Text = "Автор";
                CountList.Text = "0";
                hasJournalCheck.Checked = false;
                YearPublish.Text = "0";
                hasJournalCheck.Enabled = false;
                YearPublish.Enabled = false;
                label5.Enabled = false;
            }
            else
            {
                checkBox1.Enabled = false;
                if (!IsGoldBook(listBox1.SelectedIndex))
                {
                    Book book = new Book();
                    GetBook(ref book, listBox1.SelectedIndex);
                    NameBook.Text = book.name;
                    Author.Text = book.author;
                    CountList.Text = book.c_list.ToString();
                    hasJournalCheck.Enabled = false;
                    label5.Enabled = false;
                    YearPublish.Enabled = false;
                }
                else
                {
                    isgoldbook = true;
                    GoldBook goldbook = new GoldBook();
                    GetGoldBook(ref goldbook, listBox1.SelectedIndex);
                    NameBook.Text = goldbook.name;
                    Author.Text = goldbook.author;
                    CountList.Text = goldbook.c_list.ToString();
                    hasJournalCheck.Enabled = true;
                    label5.Enabled = true;
                    YearPublish.Enabled = true;
                    hasJournalCheck.Checked = goldbook.restor;
                    YearPublish.Text = goldbook.year_publish.ToString();
                }
            }
        }

        private void EditBook()
        {
            if (!isgoldbook)
            {
                Book book = new Book();
                book.name = NameBook.Text;
                book.author = Author.Text;
                book.c_list = int.Parse(CountList.Text);
                SetBook(ref book, listBox.SelectedIndex);
                int id = listBox.SelectedIndex;
                listBox.Items.Insert(listBox.SelectedIndex, book.name + "\t" + book.author);
                listBox.Items.RemoveAt(listBox.SelectedIndex);
                listBox.SelectedIndex = id;
            }
            else
            {
                GoldBook goldbook = new GoldBook();
                goldbook.name = NameBook.Text;
                goldbook.author = Author.Text;
                goldbook.c_list = int.Parse(CountList.Text);
                goldbook.restor = hasJournalCheck.Checked;
                goldbook.year_publish = int.Parse(YearPublish.Text);
                SetGoldBook(ref goldbook, listBox.SelectedIndex);
                int id = listBox.SelectedIndex;
                listBox.Items.Insert(listBox.SelectedIndex, goldbook.name + "\t" + goldbook.author);
                listBox.Items.RemoveAt(listBox.SelectedIndex);
                listBox.SelectedIndex = id;
            }
        }

        private void NewBook()
        {
            if (!isgoldbook)
            {
                CreateBook();
                Book book = new Book();
                book.name = NameBook.Text;
                book.author = Author.Text;
                book.c_list = int.Parse(CountList.Text);
                SetBook(ref book, GetLibrarySize() - 1);
                listBox.Items.Add(book.name + "\t" + book.author);
            }
            else
            {
                CreateGoldBook();
                GoldBook goldbook = new GoldBook();
                goldbook.name = NameBook.Text;
                goldbook.author = Author.Text;
                goldbook.c_list = int.Parse(CountList.Text);
                goldbook.restor = hasJournalCheck.Checked;
                goldbook.year_publish = int.Parse(YearPublish.Text);
                SetGoldBook(ref goldbook, GetLibrarySize() - 1);
                listBox.Items.Add(goldbook.name +"\t"+ goldbook.author);
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (isEditing)
                EditBook();
            else
                NewBook();

            OnCloseDialog?.Invoke();
            Close();
        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            isgoldbook = !isgoldbook;
            if (!isgoldbook)
            {
                hasJournalCheck.Checked = false;
                YearPublish.Text = "";
                hasJournalCheck.Enabled = false;
                YearPublish.Enabled = false;
                label5.Enabled = false;
            }
            else
            {
                YearPublish.Text = "0";
                hasJournalCheck.Enabled = true;
                YearPublish.Enabled = true;
                label5.Enabled = true;
            }
        }
    }
}
