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
    public partial class Form1 : Form
    {
        #region Header
        public bool isHeadman = false;
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
        
        public Form1()
        {
            InitializeComponent();
        }

        private void UpdateBookInfo()
        {
            if (listBox1.SelectedIndex < 0)
                return;
            if (!IsGoldBook(listBox1.SelectedIndex))
            {
                Book book = new Book();
                GetBook(ref book, listBox1.SelectedIndex);
                textBox1.Text = book.name;
                textBox2.Text = book.author;
                textBox3.Text = $"{book.c_list}";
                textBox4.Text = "";
                textBox5.Text = "";
            }
            else
            {
                GoldBook goldbook = new GoldBook();
                GetGoldBook(ref goldbook, listBox1.SelectedIndex);
                textBox1.Text = goldbook.name;
                textBox2.Text = goldbook.author;
                textBox3.Text = $"{goldbook.c_list}";
                textBox4.Text = goldbook.restor ? "Да" : "Нет";
                textBox5.Text = $"{goldbook.year_publish}";
            }
        }

        private void buttonLoad_Click(object sender, EventArgs e)
        {
            OpenFileDialog fileDialog = new OpenFileDialog
            {
                Filter = "All files (*.*)|*.*|txt files (*.txt)|*.txt|(*.mymfc*)|*.mymfc*",
                InitialDirectory = Directory.GetCurrentDirectory()
            };

            if (fileDialog.ShowDialog() == DialogResult.OK)
            {
                var fileName = new StringBuilder(fileDialog.FileName);
                LoadFromFile(fileName);
                listBox1.Items.Clear();
                for (int i = 0; i < GetLibrarySize(); i++)
                {
                    if (IsGoldBook(i))
                    {
                        GoldBook goldbook = new GoldBook();
                        GetGoldBook(ref goldbook, i);
                        listBox1.Items.Add(goldbook.name + "\t" + goldbook.author);
                    }
                    else
                    {
                        Book book = new Book();
                        GetBook(ref book, i);
                        listBox1.Items.Add(book.name + "\t" + book.author);
                    }
                }
            }
            if (GetLibrarySize() != 0)
                listBox1.SelectedIndex = 0;
        }

        private void buttonAdd_Click(object sender, EventArgs e)
        {
            Form2 dialog = new Form2(ref listBox1, UpdateBookInfo);
            dialog.ShowDialog();
        }

        private void buttonSave_Click(object sender, EventArgs e)
        {
            SaveFileDialog fileDialog = new SaveFileDialog
            {
                Filter = "All files (*.*)|*.*|txt files (*.txt)|*.txt|(*.mymfc*)|*.mymfc*",
                InitialDirectory = Directory.GetCurrentDirectory(),
                CreatePrompt = true
            };

            if (fileDialog.ShowDialog() == DialogResult.OK)
            {
                var fileName = new StringBuilder(fileDialog.FileName);
                SaveToFile(fileName);
            }
        }

        private void buttonDelet_Click(object sender, EventArgs e)
        {
            int index = listBox1.SelectedIndex;

            if (listBox1.SelectedIndex >= 0)
            {
                DeleteBook(index);
                listBox1.Items.RemoveAt(index);
            }
        }

        private void buttonRedact_Click(object sender, EventArgs e)
        {
            if (GetLibrarySize() != 0)
            {
                if (listBox1.SelectedIndex == -1)
                    listBox1.SelectedIndex = 0;
                Form2 dialog = new Form2(ref listBox1, UpdateBookInfo, true);
                dialog.ShowDialog();
            }
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (GetLibrarySize() != 0)
            {
                if (listBox1.SelectedIndex == -1)
                    listBox1.SelectedIndex = 0;
                UpdateBookInfo();
            }
        }
    }
}
