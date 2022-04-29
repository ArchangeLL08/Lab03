#pragma once


namespace Project6 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:	
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ оПрограммеToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ выходToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ действияToolStripMenuItem;
	private: System::Windows::Forms::ColorDialog^ colorDialog1;
	private: System::Windows::Forms::ToolStripMenuItem^ обновитьToolStripMenuItem;
	private: System::Windows::Forms::GroupBox^ groupBox7;
	public: System::Windows::Forms::NumericUpDown^ numericUpDown;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::RadioButton^ radioButton2;



	private: System::Windows::Forms::GroupBox^ groupBox11;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TrackBar^ trackBar2;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::TrackBar^ trackBar3;
	private: System::Windows::Forms::GroupBox^ groupBox4;
	public: System::Windows::Forms::NumericUpDown^ numericUpDown1;
	private: System::Windows::Forms::GroupBox^ groupBox5;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::Label^ label18;
	private: System::Windows::Forms::Label^ label19;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::Button^ button4;

	private: System::Windows::Forms::GroupBox^ groupBox6;
	public: System::Windows::Forms::Label^ label3;
	private:
	public: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label4;
	public:
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	public: System::Windows::Forms::Label^ label20;
	private:
	private: System::Windows::Forms::Label^ label21;
	private: System::Windows::Forms::Label^ label22;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::GroupBox^ groupBox8;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;


	public:
	public:
	private: System::Windows::Forms::TrackBar^ trackBar1;
	float func(float x);
	

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}



	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->действияToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->обновитьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->оПрограммеToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->выходToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->groupBox7 = (gcnew System::Windows::Forms::GroupBox());
			this->numericUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox11 = (gcnew System::Windows::Forms::GroupBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->trackBar2 = (gcnew System::Windows::Forms::TrackBar());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->trackBar3 = (gcnew System::Windows::Forms::TrackBar());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox8 = (gcnew System::Windows::Forms::GroupBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			this->groupBox7->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox11->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->BeginInit();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			this->groupBox3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar3))->BeginInit();
			this->groupBox4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->groupBox5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->groupBox6->SuspendLayout();
			this->groupBox8->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->действияToolStripMenuItem,
					this->оПрограммеToolStripMenuItem, this->выходToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(917, 24);
			this->menuStrip1->TabIndex = 13;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// действияToolStripMenuItem
			// 
			this->действияToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->обновитьToolStripMenuItem });
			this->действияToolStripMenuItem->Name = L"действияToolStripMenuItem";
			this->действияToolStripMenuItem->Size = System::Drawing::Size(70, 20);
			this->действияToolStripMenuItem->Text = L"Действия";
			// 
			// обновитьToolStripMenuItem
			// 
			this->обновитьToolStripMenuItem->Name = L"обновитьToolStripMenuItem";
			this->обновитьToolStripMenuItem->Size = System::Drawing::Size(128, 22);
			this->обновитьToolStripMenuItem->Text = L"Обновить";
			this->обновитьToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::обновитьToolStripMenuItem_Click);
			// 
			// оПрограммеToolStripMenuItem
			// 
			this->оПрограммеToolStripMenuItem->Name = L"оПрограммеToolStripMenuItem";
			this->оПрограммеToolStripMenuItem->Size = System::Drawing::Size(94, 20);
			this->оПрограммеToolStripMenuItem->Text = L"О программе";
			this->оПрограммеToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::оПрограммеToolStripMenuItem_Click);
			// 
			// выходToolStripMenuItem
			// 
			this->выходToolStripMenuItem->Name = L"выходToolStripMenuItem";
			this->выходToolStripMenuItem->Size = System::Drawing::Size(54, 20);
			this->выходToolStripMenuItem->Text = L"Выход";
			this->выходToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::выходToolStripMenuItem_Click);
			// 
			// groupBox7
			// 
			this->groupBox7->Controls->Add(this->numericUpDown);
			this->groupBox7->Location = System::Drawing::Point(520, 358);
			this->groupBox7->Name = L"groupBox7";
			this->groupBox7->Size = System::Drawing::Size(215, 49);
			this->groupBox7->TabIndex = 14;
			this->groupBox7->TabStop = false;
			this->groupBox7->Text = L"Размер популяции";
			// 
			// numericUpDown
			// 
			this->numericUpDown->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->numericUpDown->Location = System::Drawing::Point(61, 19);
			this->numericUpDown->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->numericUpDown->Name = L"numericUpDown";
			this->numericUpDown->Size = System::Drawing::Size(138, 20);
			this->numericUpDown->TabIndex = 10;
			this->numericUpDown->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->numericUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(562, 524);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 15;
			this->button3->Text = L"Начать";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->radioButton1);
			this->groupBox1->Controls->Add(this->radioButton2);
			this->groupBox1->Location = System::Drawing::Point(26, 42);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(144, 133);
			this->groupBox1->TabIndex = 16;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Кодирование";
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->radioButton1->Location = System::Drawing::Point(19, 64);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(104, 17);
			this->radioButton1->TabIndex = 1;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Целочисленное";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->radioButton2->Location = System::Drawing::Point(19, 28);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(100, 17);
			this->radioButton2->TabIndex = 0;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Вещественное";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// groupBox11
			// 
			this->groupBox11->Controls->Add(this->label6);
			this->groupBox11->Controls->Add(this->label8);
			this->groupBox11->Controls->Add(this->label9);
			this->groupBox11->Controls->Add(this->trackBar2);
			this->groupBox11->Location = System::Drawing::Point(520, 42);
			this->groupBox11->Name = L"groupBox11";
			this->groupBox11->Size = System::Drawing::Size(368, 81);
			this->groupBox11->TabIndex = 22;
			this->groupBox11->TabStop = false;
			this->groupBox11->Text = L"Мутации";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label6->Location = System::Drawing::Point(315, 40);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(28, 17);
			this->label6->TabIndex = 23;
			this->label6->Text = L"5%";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label8->Location = System::Drawing::Point(265, 21);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(33, 13);
			this->label8->TabIndex = 20;
			this->label8->Text = L"100%";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label9->Location = System::Drawing::Point(26, 19);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(21, 13);
			this->label9->TabIndex = 19;
			this->label9->Text = L"0%";
			// 
			// trackBar2
			// 
			this->trackBar2->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->trackBar2->Location = System::Drawing::Point(30, 29);
			this->trackBar2->Maximum = 100;
			this->trackBar2->Name = L"trackBar2";
			this->trackBar2->Size = System::Drawing::Size(268, 45);
			this->trackBar2->TabIndex = 22;
			this->trackBar2->Value = 5;
			this->trackBar2->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar2_Scroll);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->label7);
			this->groupBox2->Controls->Add(this->label10);
			this->groupBox2->Controls->Add(this->label11);
			this->groupBox2->Controls->Add(this->trackBar1);
			this->groupBox2->Location = System::Drawing::Point(520, 122);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(368, 85);
			this->groupBox2->TabIndex = 23;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Порог отсечения";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label7->Location = System::Drawing::Point(315, 36);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(36, 17);
			this->label7->TabIndex = 23;
			this->label7->Text = L"50%";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label10->Location = System::Drawing::Point(265, 21);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(33, 13);
			this->label10->TabIndex = 20;
			this->label10->Text = L"100%";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label11->Location = System::Drawing::Point(26, 19);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(21, 13);
			this->label11->TabIndex = 19;
			this->label11->Text = L"0%";
			// 
			// trackBar1
			// 
			this->trackBar1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->trackBar1->Location = System::Drawing::Point(23, 36);
			this->trackBar1->Maximum = 100;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(268, 45);
			this->trackBar1->TabIndex = 22;
			this->trackBar1->Value = 50;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar1_Scroll);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->label12);
			this->groupBox3->Controls->Add(this->label13);
			this->groupBox3->Controls->Add(this->label14);
			this->groupBox3->Controls->Add(this->trackBar3);
			this->groupBox3->Location = System::Drawing::Point(520, 213);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(368, 84);
			this->groupBox3->TabIndex = 24;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Вероятность скрещивания";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label12->Location = System::Drawing::Point(315, 36);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(36, 17);
			this->label12->TabIndex = 23;
			this->label12->Text = L"90%";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label13->Location = System::Drawing::Point(265, 21);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(33, 13);
			this->label13->TabIndex = 20;
			this->label13->Text = L"100%";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label14->Location = System::Drawing::Point(26, 19);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(21, 13);
			this->label14->TabIndex = 19;
			this->label14->Text = L"0%";
			// 
			// trackBar3
			// 
			this->trackBar3->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->trackBar3->Location = System::Drawing::Point(23, 36);
			this->trackBar3->Maximum = 100;
			this->trackBar3->Name = L"trackBar3";
			this->trackBar3->Size = System::Drawing::Size(268, 45);
			this->trackBar3->TabIndex = 22;
			this->trackBar3->Value = 90;
			this->trackBar3->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar3_Scroll);
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->numericUpDown1);
			this->groupBox4->Location = System::Drawing::Point(520, 303);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(215, 49);
			this->groupBox4->TabIndex = 25;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Количество итераций";
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(61, 19);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 500, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(138, 20);
			this->numericUpDown1->TabIndex = 11;
			this->numericUpDown1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->label4);
			this->groupBox5->Controls->Add(this->label5);
			this->groupBox5->Controls->Add(this->textBox1);
			this->groupBox5->Controls->Add(this->textBox2);
			this->groupBox5->Controls->Add(this->label17);
			this->groupBox5->Controls->Add(this->label18);
			this->groupBox5->Controls->Add(this->label19);
			this->groupBox5->Controls->Add(this->textBox6);
			this->groupBox5->Controls->Add(this->textBox7);
			this->groupBox5->Controls->Add(this->textBox8);
			this->groupBox5->Location = System::Drawing::Point(176, 42);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(325, 133);
			this->groupBox5->TabIndex = 26;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Параметры графика";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(159, 31);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(39, 13);
			this->label4->TabIndex = 17;
			this->label4->Text = L"Ymax=";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(159, 58);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(39, 13);
			this->label5->TabIndex = 18;
			this->label5->Text = L"Ymin =";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(204, 29);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 19;
			this->textBox1->Text = L"100";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(204, 55);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 20;
			this->textBox2->Text = L"-100";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(12, 88);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(36, 13);
			this->label17->TabIndex = 13;
			this->label17->Text = L"Шаг =";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(12, 32);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(24, 13);
			this->label18->TabIndex = 11;
			this->label18->Text = L"x0=";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(12, 59);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(24, 13);
			this->label19->TabIndex = 12;
			this->label19->Text = L"x1=";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(45, 28);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(100, 20);
			this->textBox6->TabIndex = 14;
			this->textBox6->Text = L"0";
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(45, 85);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(100, 20);
			this->textBox7->TabIndex = 15;
			this->textBox7->Text = L"1";
			// 
			// textBox8
			// 
			this->textBox8->Enabled = false;
			this->textBox8->Location = System::Drawing::Point(45, 56);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(100, 20);
			this->textBox8->TabIndex = 16;
			this->textBox8->Text = L"20";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(72, 16);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(0, 13);
			this->label15->TabIndex = 27;
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(73, 38);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(0, 13);
			this->label16->TabIndex = 28;
			// 
			// chart1
			// 
			chartArea2->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea2);
			legend2->Name = L"Legend1";
			this->chart1->Legends->Add(legend2);
			this->chart1->Location = System::Drawing::Point(29, 181);
			this->chart1->Name = L"chart1";
			series3->BorderWidth = 2;
			series3->ChartArea = L"ChartArea1";
			series3->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series3->Color = System::Drawing::Color::Red;
			series3->Legend = L"Legend1";
			series3->Name = L"Fср(t)";
			series4->BorderWidth = 2;
			series4->ChartArea = L"ChartArea1";
			series4->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series4->Color = System::Drawing::Color::Blue;
			series4->Legend = L"Legend1";
			series4->Name = L"Fmin(t)";
			this->chart1->Series->Add(series3);
			this->chart1->Series->Add(series4);
			this->chart1->Size = System::Drawing::Size(472, 329);
			this->chart1->TabIndex = 29;
			this->chart1->Text = L"chart1";
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(176, 524);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(145, 23);
			this->button4->TabIndex = 30;
			this->button4->Text = L"Построить график";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// groupBox6
			// 
			this->groupBox6->Controls->Add(this->label20);
			this->groupBox6->Controls->Add(this->label21);
			this->groupBox6->Controls->Add(this->label3);
			this->groupBox6->Controls->Add(this->label2);
			this->groupBox6->Controls->Add(this->label15);
			this->groupBox6->Controls->Add(this->label16);
			this->groupBox6->Location = System::Drawing::Point(520, 413);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(368, 97);
			this->groupBox6->TabIndex = 32;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"Значения";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(18, 64);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(19, 13);
			this->label20->TabIndex = 35;
			this->label20->Text = L"t =";
			this->label20->Visible = false;
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(72, 64);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(0, 13);
			this->label21->TabIndex = 34;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(18, 38);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(30, 13);
			this->label3->TabIndex = 33;
			this->label3->Text = L"f(x) =";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(18, 16);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(21, 13);
			this->label2->TabIndex = 32;
			this->label2->Text = L"x =";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(20, 26);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(33, 13);
			this->label22->TabIndex = 33;
			this->label22->Text = L"eps =";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(59, 23);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(64, 20);
			this->textBox3->TabIndex = 34;
			this->textBox3->Text = L"0.001";
			// 
			// groupBox8
			// 
			this->groupBox8->Controls->Add(this->button1);
			this->groupBox8->Controls->Add(this->textBox3);
			this->groupBox8->Controls->Add(this->label22);
			this->groupBox8->Enabled = false;
			this->groupBox8->Location = System::Drawing::Point(746, 303);
			this->groupBox8->Name = L"groupBox8";
			this->groupBox8->Size = System::Drawing::Size(142, 104);
			this->groupBox8->TabIndex = 35;
			this->groupBox8->TabStop = false;
			this->groupBox8->Text = L"До заданной точности";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(42, 55);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 36;
			this->button1->Text = L"Начать";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Enabled = false;
			this->button2->Location = System::Drawing::Point(673, 524);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(215, 23);
			this->button2->TabIndex = 36;
			this->button2->Text = L"Обновить параметры и продолжить";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CausesValidation = false;
			this->ClientSize = System::Drawing::Size(917, 630);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->groupBox8);
			this->Controls->Add(this->groupBox6);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->groupBox5);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox11);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->groupBox7);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Лабораторная работа №3";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBox7->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox11->ResumeLayout(false);
			this->groupBox11->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar3))->EndInit();
			this->groupBox4->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->groupBox6->ResumeLayout(false);
			this->groupBox6->PerformLayout();
			this->groupBox8->ResumeLayout(false);
			this->groupBox8->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
	private: double a, b, h;
	private: double x, y, y1;
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void обновитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void выходToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void trackBar2_Scroll(System::Object^ sender, System::EventArgs^ e);
	private: System::Void trackBar1_Scroll(System::Object^ sender, System::EventArgs^ e);
	private: System::Void trackBar3_Scroll(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e);

//private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void оПрограммеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
};
}
