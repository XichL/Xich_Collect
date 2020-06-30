#pragma once

namespace ALG_Tools {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;

	/// <summary>
	/// MyForm ���K�n
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void);


	protected:
		/// <summary>
		/// �M������ϥΤ����귽�C
		/// </summary>
		~MyForm();

	private:
		String^ LoadFilePath;
		Thread^ ReadLogThread;
		int readDelayTime; //ms
		bool threadRun;

	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;


	protected:



	private: System::Windows::Forms::ToolTip^  toolTip1;











	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// �]�p�u��һݪ��ܼơC
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����]�p�u��䴩�һݪ���k - �ФŨϥε{���X�s�边�ק�
		/// �o�Ӥ�k�����e�C
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->SuspendLayout();
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoValidate = System::Windows::Forms::AutoValidate::EnablePreventFocusChange;
			this->ClientSize = System::Drawing::Size(784, 561);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm::MyForm_FormClosing);
			this->Shown += gcnew System::EventHandler(this, &MyForm::MyForm_Shown);
			this->ResumeLayout(false);

		}
#pragma endregion


	private: System::Void MyForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) 
	{
		if (this->ReadLogThread&&this->ReadLogThread->IsAlive)
			this->ReadLogThread->Abort();

		GC::Collect();
	}

	private: System::Void MyForm_Shown(System::Object^  sender, System::EventArgs^  e)
	{

	}

	/// <summary>
	/// Ū�ɰ����
	/// </summary>
	private: static void ReadMessageThread(Object ^ Form);
	};
}
