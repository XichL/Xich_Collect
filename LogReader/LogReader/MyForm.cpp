#include "stdafx.h"
#include "MyForm.h"

using namespace System;
using namespace LogReader;

[STAThreadAttribute]
int main()
{
	// �إߥ��󱱨���e�A���ҥ� Windows XP ��ı�ƮĪG
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	// �إߥD�����ð���
	Application::Run(gcnew MyForm());
	return 0;
}

MyForm::MyForm()
{
	InitializeComponent();
	//
	//TODO:  �b���[�J�غc�禡�{���X
	LoadFilePath = IO::Path::GetDirectoryName(Application::ExecutablePath) + "\\Log.txt";
	readDelayTime = 1000;
	//
}

MyForm::~MyForm()
{
	if (components)
	{
		delete components;
	}
}

void MyForm::ReadMessageThread(Object ^ Form)
{
	MyForm^ myForm = static_cast<MyForm^>(Form);

	myForm->buttonAllow(false, true);
	try
	{
		do
		{
			String^ strText;
			// �P�w�ɮ׬O�_�s�b
			if (!IO::File::Exists(myForm->LoadFilePath))
			{
				strText = "No file exists";
				myForm->buttonAllow(true, false);
				break;
			}
			else
			{
				strText = IO::File::ReadAllText(myForm->LoadFilePath);
			}
			myForm->SetMessage2Handler(strText);

			Sleep(myForm->readDelayTime);

		} while (1);
	}
	catch (Exception^ e)
	{
		String^ strText = "Read exception." +
			Environment::NewLine +
			String::Format("{0:0}", e);
		myForm->SetMessage2Handler(strText);
		myForm->buttonAllow(true, false);
	}

}

void MyForm::SetMessage2Handler(String ^ message)
{
	if (this->InvokeRequired)
	{
		this->Invoke(gcnew SetMessage2Handler_Delegate(this, &MyForm::SetMessage2Handler), message);
	}
	else
	{
		this->richTextBox_LogShow->Text = message;
	}
}

void MyForm::buttonAllow(bool bStart, bool bStop)
{
	if (this->InvokeRequired)
	{
		this->Invoke(gcnew buttonAllow_Delegate(this, &MyForm::buttonAllow),
			gcnew array<Object^>{bStart, bStop});
	}
	else
	{
		this->button_Start->Enabled = bStart;
		this->button_Stop->Enabled = bStop;
	}
}
