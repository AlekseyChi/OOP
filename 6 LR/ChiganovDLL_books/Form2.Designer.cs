
namespace ChiganovDLL_books
{
    partial class Form2
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.label5 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.YearPublish = new System.Windows.Forms.TextBox();
            this.CountList = new System.Windows.Forms.TextBox();
            this.Author = new System.Windows.Forms.TextBox();
            this.NameBook = new System.Windows.Forms.TextBox();
            this.checkBox1 = new System.Windows.Forms.CheckBox();
            this.hasJournalCheck = new System.Windows.Forms.CheckBox();
            this.button1 = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(12, 239);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(90, 17);
            this.label5.TabIndex = 8;
            this.label5.Text = "Год выпуска";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(12, 142);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(144, 17);
            this.label3.TabIndex = 10;
            this.label3.Text = "Количество страниц";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(12, 90);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(47, 17);
            this.label2.TabIndex = 11;
            this.label2.Text = "Автор";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 40);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(72, 17);
            this.label1.TabIndex = 12;
            this.label1.Text = "Название";
            // 
            // YearPublish
            // 
            this.YearPublish.Location = new System.Drawing.Point(15, 259);
            this.YearPublish.Name = "YearPublish";
            this.YearPublish.Size = new System.Drawing.Size(247, 22);
            this.YearPublish.TabIndex = 3;
            // 
            // CountList
            // 
            this.CountList.Location = new System.Drawing.Point(15, 162);
            this.CountList.Name = "CountList";
            this.CountList.Size = new System.Drawing.Size(247, 22);
            this.CountList.TabIndex = 5;
            // 
            // Author
            // 
            this.Author.Location = new System.Drawing.Point(15, 110);
            this.Author.Name = "Author";
            this.Author.Size = new System.Drawing.Size(247, 22);
            this.Author.TabIndex = 6;
            // 
            // NameBook
            // 
            this.NameBook.Location = new System.Drawing.Point(15, 60);
            this.NameBook.Name = "NameBook";
            this.NameBook.Size = new System.Drawing.Size(247, 22);
            this.NameBook.TabIndex = 7;
            // 
            // checkBox1
            // 
            this.checkBox1.AutoSize = true;
            this.checkBox1.Location = new System.Drawing.Point(15, 13);
            this.checkBox1.Name = "checkBox1";
            this.checkBox1.Size = new System.Drawing.Size(219, 21);
            this.checkBox1.TabIndex = 13;
            this.checkBox1.Text = "Книга из золотой коллекции";
            this.checkBox1.UseVisualStyleBackColor = true;
            this.checkBox1.CheckedChanged += new System.EventHandler(this.checkBox1_CheckedChanged);
            // 
            // hasJournalCheck
            // 
            this.hasJournalCheck.AutoSize = true;
            this.hasJournalCheck.Location = new System.Drawing.Point(17, 202);
            this.hasJournalCheck.Name = "hasJournalCheck";
            this.hasJournalCheck.Size = new System.Drawing.Size(139, 21);
            this.hasJournalCheck.TabIndex = 13;
            this.hasJournalCheck.Text = "Реставрирована";
            this.hasJournalCheck.UseVisualStyleBackColor = true;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(90, 287);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(93, 32);
            this.button1.TabIndex = 14;
            this.button1.Text = "ОК";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // Form2
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(286, 331);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.hasJournalCheck);
            this.Controls.Add(this.checkBox1);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.YearPublish);
            this.Controls.Add(this.CountList);
            this.Controls.Add(this.Author);
            this.Controls.Add(this.NameBook);
            this.Name = "Form2";
            this.Text = "Изменение";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox YearPublish;
        private System.Windows.Forms.TextBox CountList;
        private System.Windows.Forms.TextBox Author;
        private System.Windows.Forms.TextBox NameBook;
        private System.Windows.Forms.CheckBox checkBox1;
        private System.Windows.Forms.CheckBox hasJournalCheck;
        private System.Windows.Forms.Button button1;
    }
}