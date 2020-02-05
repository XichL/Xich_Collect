#pragma once

namespace LogReader {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;

	/// <summary>
	/// MyForm 的摘要
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void);


	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~MyForm();

	private:
		String^ LoadFilePath;
		Thread^ ReadLogThread;
		int readDelayTime; //ms

	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::RichTextBox^  richTextBox_LogShow;

	protected:

	private: System::Windows::Forms::TextBox^  textBox_LoadFilePath;
	private: System::Windows::Forms::Button^  button_FileBrows;
	private: System::Windows::Forms::ToolTip^  toolTip1;
	private: System::Windows::Forms::Button^  button_Clean;
	private: System::Windows::Forms::Button^  button_Stop;
	private: System::Windows::Forms::Button^  button_Start;
	private: System::Windows::Forms::TextBox^  textBox_LoadDelayTime;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  button_FileSet;
	private: System::Windows::Forms::Button^  button_NowPath;


	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->richTextBox_LogShow = (gcnew System::Windows::Forms::RichTextBox());
			this->textBox_LoadFilePath = (gcnew System::Windows::Forms::TextBox());
			this->button_FileBrows = (gcnew System::Windows::Forms::Button());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->button_Clean = (gcnew System::Windows::Forms::Button());
			this->button_Stop = (gcnew System::Windows::Forms::Button());
			this->button_Start = (gcnew System::Windows::Forms::Button());
			this->textBox_LoadDelayTime = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button_FileSet = (gcnew System::Windows::Forms::Button());
			this->button_NowPath = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// richTextBox_LogShow
			// 
			this->richTextBox_LogShow->Location = System::Drawing::Point(12, 12);
			this->richTextBox_LogShow->Name = L"richTextBox_LogShow";
			this->richTextBox_LogShow->Size = System::Drawing::Size(640, 480);
			this->richTextBox_LogShow->TabIndex = 0;
			this->richTextBox_LogShow->Text = L"";
			// 
			// textBox_LoadFilePath
			// 
			this->textBox_LoadFilePath->Location = System::Drawing::Point(12, 527);
			this->textBox_LoadFilePath->Name = L"textBox_LoadFilePath";
			this->textBox_LoadFilePath->Size = System::Drawing::Size(760, 22);
			this->textBox_LoadFilePath->TabIndex = 1;
			// 
			// button_FileBrows
			// 
			this->button_FileBrows->Location = System::Drawing::Point(580, 498);
			this->button_FileBrows->Name = L"button_FileBrows";
			this->button_FileBrows->Size = System::Drawing::Size(60, 23);
			this->button_FileBrows->TabIndex = 2;
			this->button_FileBrows->Text = L"Brows";
			this->button_FileBrows->UseVisualStyleBackColor = true;
			this->button_FileBrows->Click += gcnew System::EventHandler(this, &MyForm::button_PathBrows_Click);
			// 
			// button_Clean
			// 
			this->button_Clean->Location = System::Drawing::Point(658, 12);
			this->button_Clean->Name = L"button_Clean";
			this->button_Clean->Size = System::Drawing::Size(54, 23);
			this->button_Clean->TabIndex = 4;
			this->button_Clean->Text = L"Clean";
			this->button_Clean->UseVisualStyleBackColor = true;
			this->button_Clean->Click += gcnew System::EventHandler(this, &MyForm::button_Clean_Click);
			// 
			// button_Stop
			// 
			this->button_Stop->Location = System::Drawing::Point(718, 41);
			this->button_Stop->Name = L"button_Stop";
			this->button_Stop->Size = System::Drawing::Size(54, 23);
			this->button_Stop->TabIndex = 5;
			this->button_Stop->Text = L"Stop";
			this->button_Stop->UseVisualStyleBackColor = true;
			this->button_Stop->Click += gcnew System::EventHandler(this, &MyForm::button_Stop_Click);
			// 
			// button_Start
			// 
			this->button_Start->Location = System::Drawing::Point(658, 41);
			this->button_Start->Name = L"button_Start";
			this->button_Start->Size = System::Drawing::Size(54, 23);
			this->button_Start->TabIndex = 6;
			this->button_Start->Text = L"Start";
			this->button_Start->UseVisualStyleBackColor = true;
			this->button_Start->Click += gcnew System::EventHandler(this, &MyForm::button_Start_Click);
			// 
			// textBox_LoadDelayTime
			// 
			this->textBox_LoadDelayTime->Location = System::Drawing::Point(658, 106);
			this->textBox_LoadDelayTime->Name = L"textBox_LoadDelayTime";
			this->textBox_LoadDelayTime->Size = System::Drawing::Size(91, 22);
			this->textBox_LoadDelayTime->TabIndex = 7;
			this->textBox_LoadDelayTime->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox_LoadDelayTime_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(755, 116);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(17, 12);
			this->label1->TabIndex = 8;
			this->label1->Text = L"(s)";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(658, 91);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(83, 12);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Load delay time:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 509);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(97, 12);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Now load file path: ";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// button_FileSet
			// 
			this->button_FileSet->Location = System::Drawing::Point(646, 498);
			this->button_FileSet->Name = L"button_FileSet";
			this->button_FileSet->Size = System::Drawing::Size(60, 23);
			this->button_FileSet->TabIndex = 11;
			this->button_FileSet->Text = L"Set";
			this->button_FileSet->UseVisualStyleBackColor = true;
			this->button_FileSet->Click += gcnew System::EventHandler(this, &MyForm::button_PathSet_Click);
			// 
			// button_NowPath
			// 
			this->button_NowPath->Location = System::Drawing::Point(712, 498);
			this->button_NowPath->Name = L"button_NowPath";
			this->button_NowPath->Size = System::Drawing::Size(60, 23);
			this->button_NowPath->TabIndex = 12;
			this->button_NowPath->Text = L"Now path";
			this->button_NowPath->UseVisualStyleBackColor = true;
			this->button_NowPath->Click += gcnew System::EventHandler(this, &MyForm::button_NowPath_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoValidate = System::Windows::Forms::AutoValidate::EnablePreventFocusChange;
			this->ClientSize = System::Drawing::Size(784, 561);
			this->Controls->Add(this->button_NowPath);
			this->Controls->Add(this->button_FileSet);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox_LoadDelayTime);
			this->Controls->Add(this->button_Start);
			this->Controls->Add(this->button_Stop);
			this->Controls->Add(this->button_Clean);
			this->Controls->Add(this->button_FileBrows);
			this->Controls->Add(this->textBox_LoadFilePath);
			this->Controls->Add(this->richTextBox_LogShow);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm::MyForm_FormClosing);
			this->Shown += gcnew System::EventHandler(this, &MyForm::MyForm_Shown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button_Clean_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		this->richTextBox_LogShow->Clear();
	}

	private: System::Void button_Start_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		this->ReadLogThread = gcnew Thread(gcnew ParameterizedThreadStart(&ReadMessageThread));
		this->ReadLogThread->IsBackground = true;
		this->ReadLogThread->Start(this);

		this->buttonAllow(false, true);
	}

	private: System::Void button_Stop_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (this->ReadLogThread->IsAlive)
			this->ReadLogThread->Abort();

		this->buttonAllow(true, false);
	}

	private: System::Void button_PathBrows_Click(System::Object^  sender, System::EventArgs^  e)
	{
		try
		{
			this->openFileDialog1 = gcnew OpenFileDialog();
			openFileDialog1->InitialDirectory = ".//";
			openFileDialog1->Filter = "TXT|*.txt|";

			if (this->openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				this->textBox_LoadFilePath->Text = this->openFileDialog1->FileName;
			}
		}
		catch (Exception^ e)
		{
			this->richTextBox_LogShow->Text = String::Format("{0:0}", e);
			this->textBox_LoadFilePath->Text = "Brows exception";
		}
	}

	private: System::Void button_PathSet_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->LoadFilePath = this->textBox_LoadFilePath->Text;
	}

	private: System::Void MyForm_Shown(System::Object^  sender, System::EventArgs^  e)
	{
		this->textBox_LoadFilePath->Text = this->LoadFilePath;
		this->textBox_LoadDelayTime->Text = "1";
		this->buttonAllow(true, false);
	}

	private: System::Void button_NowPath_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->textBox_LoadFilePath->Text = this->LoadFilePath;
	}

	private: System::Void textBox_LoadDelayTime_TextChanged(System::Object^  sender, System::EventArgs^  e)
	{
		int EnterTime = Convert::ToInt32(this->textBox_LoadDelayTime->Text) * 1000;
		Sleep(500);
		this->readDelayTime = EnterTime;
	}

	private: System::Void MyForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) 
	{
		if (this->ReadLogThread->IsAlive)
			this->ReadLogThread->Abort();

		GC::Collect();
	}

	/// <summary>
	/// 讀檔執行緒
	/// </summary>
	private: static void ReadMessageThread(Object ^ Form);

	/// <summary>
	/// 將文字讀入Box中
	/// </summary>
	public: void SetMessage2Handler(String^ message);
	private: delegate void SetMessage2Handler_Delegate(String^ message);

	 /// <summary>
	/// 按鈕是否允許使用
	/// </summary>
	public: void buttonAllow(bool bStart ,bool bStop);
	private: delegate void buttonAllow_Delegate(bool bStart, bool bStop);
};
}
