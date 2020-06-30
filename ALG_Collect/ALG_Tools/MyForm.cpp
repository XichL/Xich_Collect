#include "stdafx.h"
#include "MyForm.h"

using namespace System;
using namespace ALG_Tools;

[STAThreadAttribute]
int main()
{
	// 建立任何控制項之前，先啟用 Windows XP 視覺化效果
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	// 建立主視窗並執行
	Application::Run(gcnew MyForm());
	return 0;
}

MyForm::MyForm()
{
	InitializeComponent();
	//
	//TODO:  在此加入建構函式程式碼
	LoadFilePath = IO::Path::GetDirectoryName(Application::ExecutablePath) + "\\Log.txt";
	readDelayTime = 2000;
	threadRun = false;
	//
}

MyForm::~MyForm()
{
	if (components)
	{
		delete components;
	}
}

#define	RestartTag tag
void MyForm::ReadMessageThread(Object ^ Form)
{
	MyForm^ myForm = static_cast<MyForm^>(Form);

	myForm->buttonAllow(false, true);
RestartTag:

	String^ strExceptionMsg = "Read exception ,wait prgoram restart self" + Environment::NewLine + "or press \"stop\" and \"start\" again";
	String^ lastText = String::Empty; //上一筆資料
	try
	{
		do
		{
			if (!myForm->threadRun)
			{
				return;
			}

			String^ strText;
			// 判定檔案是否存在
			if (!IO::File::Exists(myForm->LoadFilePath))
			{
				strText = "No file exists";
				Windows::Forms::MessageBox::Show("No file exists.",
					"No file",
					MessageBoxButtons::OK,
					MessageBoxIcon::Error);
				myForm->SetMessage2Handler(strText);
				Sleep(3000);
				myForm->buttonAllow(true, false);
				break;
			}
			else
			{
				strText = IO::File::ReadAllText(myForm->LoadFilePath);
				if (strText->Equals(lastText))
				{
					Sleep(myForm->readDelayTime);
					continue;
				}
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

		if (!myForm->threadRun)
		{
			return;
		}

		myForm->SetMessage2Handler(strExceptionMsg);

		Sleep(100);

		goto RestartTag;
	}
}
